#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> container;
	vector<int> problem;
	vector<string> answer;
	int push_count = 1;
	int index_count = 0;
	int pop_count = 0;
	int n;
	int temp;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		problem.push_back(temp);
	}

	// n개의 요소가 모두 pop되면 종료
	while(pop_count != n)
	{
		// stack이 비어있으면 push
		// push_count 추가 이후 +출력
		
		if (container.empty())
		{
			container.push(push_count);
			++push_count;
			answer.push_back("+");
		}
		else
		{
			// 찾고자 하는 배열의 n번째 수와 stack의 top이 일치하면
			// pop 이후(pop_count에 1 추가) - 출력
			// continue 통해 바로 넘길 수 있게 함

			if (container.top() == problem[index_count])
			{
				container.pop();
				++pop_count;
				++index_count;
				answer.push_back("-");
				continue;
			}

			// push_count 추가 이후 +출력
			if (push_count < n + 1)
			{
				container.push(push_count);
				++push_count;
				answer.push_back("+");
			}

			else
			{
				cout << "NO" << "\n";
				break;
			}
		}


	}


	if (pop_count == n)
	{
		for (auto c : answer)
		{
			cout << c << "\n";
		}
	}
	return 0;

}