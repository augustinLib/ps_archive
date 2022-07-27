#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


bool check_paren(string input)
{
	stack<char> container;
	char temp;


	for (auto c : input)
	{

		temp = c;
		// 여는 괄호를 만났을 때
		// 스택에 추가
		if (temp == '(')
		{
			container.push(temp);

		}
		// 닫는 괄호를 만났을 때
		// 비어있으면 일단 false 반환
		// 비어있는 상태에서 top연산이 실행되면 오류가 발생
		// 따라서 분기를 하나 만들어줘야함
		// stack의 top과 매칭되면 pop후 진행
		// 아니면 false 반환
		else if (temp == ')')
		{
			if (container.empty())
			{
				return false;
			}

			else if (container.top() == '(')
			{
				container.pop();
			}
			else
			{
				return false;
			}

		}
	}

	// 모든 요소를 확인 한 뒤, stack이 비어있지 않으면 NO
	if (container.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	string input;
	vector<string> answer;
	for (int i = 0; i < T;++i)
	{
		// 입력 문자열 받기
		cin >> input;
		if (check_paren(input) == true)
		{
			answer.push_back("YES");
		}
		else
		{
			answer.push_back("NO");
		}

	}

	for (auto c : answer)
	{
		cout << c << "\n";
	}
	return 0;
}