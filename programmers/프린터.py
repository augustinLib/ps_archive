def solution(priorities, location):
    
    # 프린트된 횟수를 알려주는 num_print
    num_print = 0
    
    # 현재 대기목록의 인덱스를 key값으로, 값을 value값으로 tuple로 묶어서 리스트 재생성
    for index, value in enumerate(priorities):
        priorities[index] = (index, value)
    
    # location을 찾아 return문이 나올때까지 반복
    
    while(True):
        # 현재 대기목록 맨 앞 꺼내기
        temp_index, temp_value = priorities.pop(0)
        
        # 꺼내진 후 나머지 인쇄 대기목록의 최댓값 구하기
        # 그런데, 꺼내고 난 뒤의 리스트가 비어있을 수 있다.
        # 따라서 리스트가 비어있지 않은 경우에만 최댓값을 구한 다음 비교하여 출력하고,
        # 리스트가 비어있으면 그냥 바로 출력
        if len(priorities) != 0:
            temp_list = []
            for _, val in priorities:
                temp_list.append(val)
            
            maximum = max(temp_list)
            
            # 나머지 인쇄 대기목록의 최댓값보다 꺼내진 값의 value가 크거나 같으면 인쇄
            if (maximum <= temp_value):
                num_print += 1
                
                # 프린트를 한 경우, index가 location과 같으면 num_print return
                if location == temp_index:
                    return num_print
                
                
            # 나머지 인쇄 대기목록의 최댓값보다 꺼내진 값의 value가 작으면 맨 뒤로 넣음
            else:
                priorities.append((temp_index, temp_value))
        else:
            num_print += 1
            return num_print