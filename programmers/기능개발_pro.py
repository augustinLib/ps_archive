import math

def solution(progresses, speeds):
    answer = []
    days = []
    
    for i in range(0, len(progresses)):
        days.append(math.ceil((100-progresses[i]) / speeds[i]))
        
        
    while(len(days) != 0):
        standard = days[0]
        answer.append(0)
        
        removeIndex = []
        for j in range(0, len(days)):
            if(days[j] <= standard):
                removeIndex.append(j)
                answer[-1] += 1
            else:
                break


        for idx in sorted(removeIndex, reverse = True):
            del days[idx]
            
        
    return answer