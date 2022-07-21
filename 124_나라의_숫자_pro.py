def solution(n):
    answer = ''
    temp_container = []
    
    while(True):
        
        # 몫이 0인 경우
        if(n//3 == 0):
            #n값이 0인 경우, 반복문 종료
            if(n == 0):
                break
            
            temp_container.append(n%3)
            break
            
        # 3으로 나눠떨어지는 경우
        # 일단 container에 4를 넣어준 뒤,
        # n/3 값에 -1을 해준다
        elif(n % 3 == 0):
            temp_container.append(4)
            n = n//3 - 1
            
        else:
            temp_container.append(n%3)
            n //= 3
    
    # container에 저장될 때 반대로 저장되었기 때문에, 뒤집어줌
    temp_container.reverse()
    
    # container 요소 문자열로 추가
    for i in temp_container:
        answer += str(i)
    
    
    
    return answer