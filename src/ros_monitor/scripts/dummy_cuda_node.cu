#include <ros/ros.h>
#include <std_msgs/String.h>
#include <cuda_runtime.h>

// CUDA 커널: 반복적인 행렬 덧셈 연산을 수행하여 GPU 부하 증가
__global__ void heavyKernel(float* d_A, float* d_B, float* d_C, int N, int iterations) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < N) {
        for (int i = 0; i < iterations; i++) {  // GPU 연산 반복
            d_C[idx] = d_A[idx] + d_B[idx];
        }
    }
}

void gpuComputationLoop() {
    const int N = 1024 * 1024 *10;  // 기존보다 100배 증가 (100MB 데이터)
    const int iterations = 10000;  // 연산 반복 횟수 증가
    float *d_A, *d_B, *d_C;

    // GPU 메모리 할당 (CPU 메모리 할당 X)
    cudaMalloc((void**)&d_A, N * sizeof(float));
    cudaMalloc((void**)&d_B, N * sizeof(float));
    cudaMalloc((void**)&d_C, N * sizeof(float));

    // 데이터 초기화 (GPU에서 직접 수행)
    cudaMemset(d_A, 1, N * sizeof(float));
    cudaMemset(d_B, 2, N * sizeof(float));

    // CUDA 커널 실행 설정
    dim3 blockSize(256);
    dim3 gridSize((N + blockSize.x - 1) / blockSize.x);

    while (ros::ok()) {
        heavyKernel<<<gridSize, blockSize>>>(d_A, d_B, d_C, N, iterations);
        cudaDeviceSynchronize();  // 연산 완료 대기

        ROS_INFO("Heavy CUDA kernel executed successfully");

        ros::Duration(1.0).sleep();  // 1초 대기
    }

    // GPU 메모리 해제
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "dummy_cuda_node");
    ros::NodeHandle nh;

    ROS_INFO("Dummy CUDA Node Started");

    gpuComputationLoop();  // GPU를 계속 사용하는 연산 실행

    return 0;
}
