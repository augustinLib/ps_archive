def solution(n, lost, reserve):
    
    student = [1 for i in range(0, n+2)]

    for l in lost:
        student[l] -= 1
        
    for r in reserve:
        student[r] += 1
        
    for k in range(1, n+1):
        if student[k] == 2 and student[k-1] == 0:
            student[k-1:k+1] = [1,1]
            
        elif student[k] == 2 and student[k+1] == 0:
            student[k:k+2] = [1,1]
            
    answer = len([x for x in student[1:-1] if x > 0])

    return answer