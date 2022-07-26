#include <iostream>
#include <vector>

using namespace std;

int main(void)
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, X;

	cin >> N >> X;

	int temp;
	vector<int> container;

	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		container.push_back(temp);
	}

	for (int c : container)
	{
		if (c < X)
		{
			cout << c << " ";
		}
	}
	return 0;
}

