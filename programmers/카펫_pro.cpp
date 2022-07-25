#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 가로 길이 >= 세로 길이
    // brown + yellow = 전체 격자 수
    int all = brown + yellow;
    
    // 세로 후보 돌려보기
    for (int temp_col = 1; temp_col <= (all/2)+1; ++temp_col)
    {
        // 가로 세로 후보를 찾으면
        if (all % temp_col == 0)
        {
            // 가로 후보 temp_row에 넣기
            int temp_row = all / temp_col;
            
            // brown의 개수 = (가로 + 세로)*2 - 4
            // 맞으면 가로세로 추가하고 종료
            if (brown == ((temp_row + temp_col)*2 - 4))
            {
                answer.push_back(temp_row);
                answer.push_back(temp_col);
                break;
            }
        }
    }

    
    return answer;
}