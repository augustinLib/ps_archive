def solution(A,B):
    answer = 0

    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    print('Hello Python')
    
    A.sort()
    B.sort(reverse = True)
    sum = 0
    
    for i in range(0, len(A)):
        temp = A[i] * B[i]
        sum += temp

    answer = sum    
    return answer