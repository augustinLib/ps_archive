def solution(d, budget):
    d.sort()
    
    sum = 0
    count = 0
    for i in d:
        sum += i
        if (sum > budget):
            return count

        count += 1
        
    return count