def solution(numbers):
    find_list = [i for i in range(10)]
    
    for i in numbers:
        find_list[i] = 0
        
    answer = sum(find_list)
    return answer