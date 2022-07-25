#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds);
int main(void)
{
  vector<int> progresses {93, 30, 55};
  vector<int> speeds {1, 30, 5};
  vector<int> answer;
  answer = solution(progresses, speeds);
  for (int c : answer)
    cout << c << endl;
}


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    list<int> days;
    for(auto i = 0; i < size(progresses); ++i)
    {
      //나누기에서 한 쪽이 실수형이어야만 소숫점이 살아남음
        days.push_back(ceil((100-progresses[i]) / (double)speeds[i]));
    }
    
    while(!days.empty())
    {
        auto standard = days.front();
        answer.push_back(0);
        for(auto iter = days.begin(); iter != days.end();)
        {
            
            if(*iter <= standard)
            {
                iter = days.erase(iter) ;
                ++answer.back();
            }
            else
            {
                break;
            }
        }
    }
    return answer;
}