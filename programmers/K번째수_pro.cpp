#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    // i번째부터 j번째까지 자르고 정렬했을 때, k번째에 있는 수를 구하라
    // array는 적용 대상, commands는 i, j, k가 들어있는 배열
    // command의 각 요소들을 꺼낸 뒤, 정렬 후해당 i,j,k를 array에 적용해서 answer에 저장
    // i번째 요소부터 j번째 요소까지 임시로 담을 vector생성
    vector<int> temp;
    
    //command의 각 요소 꺼내기
    for (auto command : commands)
    {
        // i번째부터 j번째까지 꺼내기
        for (int start = command[0]; start <= command[1]; ++start)
        {
            temp.push_back(array[start-1]);
        }
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[command[2]-1]);
        temp.clear();
    
    }
    
    
    return answer;
}