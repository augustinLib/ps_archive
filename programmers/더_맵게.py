import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    answer = 0
    while True:
        min1 = heapq.heappop(scoville)
        # 가장 작은 값도 K보다 크면 종료
        if min1 >= K:
            break
        # 값이 아무것도 남지 않았을 때
        elif len(scoville) == 0:
            answer = -1
            break
        
        min2 = heapq.heappop(scoville)
        new_scoville = min1 + 2 * min2
        heapq.heappush(scoville, new_scoville)
        answer += 1

    return answer

