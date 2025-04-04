#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <cupti.h>
#include <stdint.h>
#include <map>

#define CUPTI_CALL(call)                                                    \
    do {                                                                    \
        CUptiResult _status = call;                                         \
        if (_status != CUPTI_SUCCESS) {                                     \
            const char *errstr;                                             \
            cuptiGetResultString(_status, &errstr);                         \
            fprintf(stderr, "%s:%d: error: function %s failed with error %s.\n",\
                    __FILE__, __LINE__, #call, errstr);                     \
            exit(-1);                                                       \
        }                                                                   \
    } while (0)

#define CUDA_CALL(call)                                                     \
    do {                                                                    \
        cudaError_t err = call;                                             \
        if (err != cudaSuccess) {                                           \
            fprintf(stderr, "%s:%d: CUDA error: %s\n", __FILE__, __LINE__, cudaGetErrorString(err)); \
            exit(-1);                                                       \
        }                                                                   \
    } while (0)

// Dummy kernel to generate GPU activity
__global__ void dummyKernel(float *data, int N) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < N) {
        data[idx] = data[idx] * 2.0f;
    }
}

int main(void) {
    int N = 256;
    float *d_data;
    CUDA_CALL(cudaMalloc((void**)&d_data, N * sizeof(float)));
    dummyKernel<<<(N + 63) / 64, 64>>>(d_data, N);
    CUDA_CALL(cudaDeviceSynchronize());

    CUptiResult status;
    size_t bufferSize = 1024 * 1024;  // Allocate 1MB buffer
    uint8_t *buffer = (uint8_t *) malloc(bufferSize);
    if (buffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(-1);
    }

    // Enable CUPTI activities: enable both context and kernel activities.
    CUPTI_CALL(cuptiActivityEnable(CUPTI_ACTIVITY_KIND_CONTEXT));
    CUPTI_CALL(cuptiActivityEnable(CUPTI_ACTIVITY_KIND_KERNEL));

    // Synchronize the device to trigger GPU activities.
    CUDA_CALL(cudaDeviceSynchronize());

    // Flush any remaining records from CUPTI's internal buffer.
    CUPTI_CALL(cuptiActivityFlushAll(0));

    // Map to associate context ID with PID.
    std::map<uint32_t, uint32_t> contextPidMap;
    // Map to accumulate kernel execution time (in nanoseconds) per PID.
    std::map<uint32_t, uint64_t> pidKernelTime;

    CUpti_Activity *record = NULL;
    while ((status = cuptiActivityGetNextRecord(buffer, bufferSize, &record)) == CUPTI_SUCCESS) {
        switch (record->kind) {
            case CUPTI_ACTIVITY_KIND_CONTEXT: {
                CUpti_ActivityContext *ctx = (CUpti_ActivityContext *) record;
                uint32_t processId = 0;
                size_t attrSize = sizeof(processId);
#ifdef CUPTI_ACTIVITY_ATTR_CONTEXT_PROCESS_ID
                // If the CUPTI version supports the process id attribute:
                CUPTI_CALL(cuptiActivityGetObjectAttribute(
                    ctx->contextId,
                    CUPTI_ACTIVITY_OBJECT_CONTEXT,
                    CUPTI_ACTIVITY_ATTR_CONTEXT_PROCESS_ID,
                    &attrSize,
                    &processId));
#else
                // If the CUPTI version does not support the process id attribute,
                // set processId to 0.
                processId = 0;
#endif
                contextPidMap[ctx->contextId] = processId;
                break;
            }
            case CUPTI_ACTIVITY_KIND_KERNEL: {
                // Cast kernel record to CUpti_ActivityKernel4 (latest CUPTI).
                CUpti_ActivityKernel4 *kernel = (CUpti_ActivityKernel4 *) record;
                uint32_t pid = 0;
                if (contextPidMap.find(kernel->contextId) != contextPidMap.end()) {
                    pid = contextPidMap[kernel->contextId];
                }
                // Kernel execution time is provided in nanoseconds.
                uint64_t duration = kernel->end - kernel->start;
                pidKernelTime[pid] += duration;
                break;
            }
            default:
                // Ignore other types of records.
                break;
        }
    }

    if (status != CUPTI_ERROR_MAX_LIMIT_REACHED) {
        const char *errstr;
        cuptiGetResultString(status, &errstr);
        fprintf(stderr, "cuptiActivityGetNextRecord failed: %s\n", errstr);
    }

    // Print the GPU kernel execution time per PID in milliseconds.
    printf("GPU kernel execution time per PID (in milliseconds):\n");
    for (auto it = pidKernelTime.begin(); it != pidKernelTime.end(); ++it) {
        double ms = (double) it->second / 1e6; // Convert nanoseconds to milliseconds
        printf("PID %u: %.3f ms\n", it->first, ms);
    }

    free(buffer);

    // Disable CUPTI activities.
    CUPTI_CALL(cuptiActivityDisable(CUPTI_ACTIVITY_KIND_CONTEXT));
    CUPTI_CALL(cuptiActivityDisable(CUPTI_ACTIVITY_KIND_KERNEL));

    CUDA_CALL(cudaFree(d_data));
    return 0;
}
