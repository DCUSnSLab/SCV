import numpy as np
import time
import multiprocessing

# 행렬 크기 설정
MATRIX_SIZE = 500 

# 행렬 곱셈 함수 (각 프로세스가 할 일)
def matrix_multiplication_worker(i, A, B, result):
    C_row = np.zeros(MATRIX_SIZE)
    for j in range(MATRIX_SIZE):
        C_row[j] = sum(A[i, k] * B[k, j] for k in range(MATRIX_SIZE))
    result[i, :] = C_row

# 멀티프로세싱으로 행렬 곱셈 실행
def matrix_multiplication(A, B):
    result = np.zeros((MATRIX_SIZE, MATRIX_SIZE))
    processes = []

    # 멀티 프로세스 생성
    for i in range(MATRIX_SIZE):
        p = multiprocessing.Process(target=matrix_multiplication_worker, args=(i, A, B, result))
        processes.append(p)
        p.start()

    # 모든 프로세스가 끝날 때까지 기다림
    for p in processes:
        p.join()

    return result

# 랜덤 행렬 생성
A = np.random.rand(MATRIX_SIZE, MATRIX_SIZE)
B = np.random.rand(MATRIX_SIZE, MATRIX_SIZE)

# 곱셈 연산 시작 시간 측정
start_time = time.time()

# 행렬 곱셈 실행
C = matrix_multiplication(A, B)

# 시간 측정 종료
end_time = time.time()

# 실행된 시간 출력
print(f"행렬 곱셈 실행 시간 (멀티코어 사용): {end_time - start_time}초")
