#include <string>
#include <vector>

using namespace std;


string solution(int n) {
    string answer = "";
    vector<string> temp_container;
    
    // 일의자리수는 1, 2, 4로 카운팅되어져 올라감
    // 3n+1번째 수마다 자릿수가 늘어남
    

    // 해당 과정에서 나오는 나머지를 맨 끝으로 append
    
    while(true)
    {
        if (n/3 == 0)
        {
            if (n == 0)
                // 만약 n이 0이 되는 경우가 발생한다면, 바로 중지
                break;
            temp_container.push_back(to_string(n%3));
            break;
        }
        
        // 딱 나눠지는 부분에 대해서는 4를 먼저 넣고, 몫에 -1을 넣고 다시 반복문으로
        
        else if (n%3 == 0)
        {
            temp_container.push_back(to_string(4));
            n = n/3 -1;
        }
        
        else
        {
            temp_container.push_back(to_string(n%3));
            n /= 3;
        }

    }
    
    // 임시 저장소에서 역순으로 요소를 뽑아서 문자열로 결합
    for (auto i = temp_container.rbegin(); i < temp_container.rend(); ++i)
    {
        answer.append(*i);
    }

    
    return answer;
}