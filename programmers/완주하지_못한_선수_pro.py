def solution(participant, completion):
    
    hash = {}
    
    for i in participant:
        # get : 딕셔너리의 value값 가져옴
        # 두번째 인자의 경우, 반환값이 없을 때 가져오는 값 설정 가능(default : none)
        hash[i] = hash.get(i, 0) + 1
        
    for j in completion:
        hash[j] -= 1
    
    tempList = [name for name, value in hash.items() if value > 0 ]
    answer = tempList[0]
    return answer