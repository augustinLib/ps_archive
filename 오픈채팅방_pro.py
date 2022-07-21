def solution(record):
    answer = []
    
    # record : 행동 아이디 닉네임
    # 공백 split으로 나누기
    # 0: 행동
    # 1: 아이디
    # 2: 닉네임
    id_name  = {}

    # id : name 딕셔너리 생성 이후, id에 맞는 닉네임 나올 수 있게
    for _, content in enumerate(record):
        if (content.split(" ")[0] == "Enter" or content.split(" ")[0] == "Change"):
            id_name[content.split(" ")[1]] = content.split(" ")[2]
            
    for _, content in enumerate(record):
        if (content.split(" ")[0] == "Enter"):
            answer.append("%s님이 들어왔습니다." %(id_name[content.split(" ")[1]]))
        elif (content.split(" ")[0] == "Leave"):
            answer.append("%s님이 나갔습니다." %(id_name[content.split(" ")[1]]))
    
        
        
        
    
    return answer