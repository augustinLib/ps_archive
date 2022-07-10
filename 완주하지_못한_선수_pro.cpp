#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    // 내림차순 정렬
    string answer = "";
    
    // iterator 이용 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    // 둘 다 정렬되었기때문에, 참여자와 완주자가 같으면 두 vector는 같을것이다
    // 그러나 참여자와 완주자가 다르기 때문에 완주자 리스트와 참여자 리스트가 다른 그 순간이 정답
    // Ex) a,b,c 와 a,c는 b가 다르다
    // participant보다 1 짧은 completion을 돌면서
    // participant의 맨 뒤 요소와 일치하는지 검사하고
    // 한번의 반복문 횟수(다음 요소로 넘어갈 때)가 진행될때 participant 뒷 요소도 제거
    
    // pop_back()함수를 이용하기 위해 뒤에서부터 반복 진행
    for (auto iter = completion.rbegin(); iter != completion.rend(); ++iter)
    {
        // 두 리스트의 마지막 요소가 다르면 return
        if (*iter != participant.back())
        {
            answer += participant.back();
            break;
        }
        // 매 반복마다 participant 뒷요소(검사가 완료된) 제거하여 다음 요소와 검사될 수 있게 함
        participant.pop_back();
    }
    
    // 아직 answer이 없는 경우에는 검사되지 못한 participant의 첫번째 요소가 정답
    if (answer.empty())
    {
        answer += participant.front();
    }
    
    return answer;
}