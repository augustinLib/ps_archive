#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// N : 나무의 수, M : 집으로 가져가는 나무의 길이
	long long M, N;
	long long temp;
	vector<long long> tree_height;
	cin >> N >> M;



	for (long long i = 0; i < N; ++i)
	{
		cin >> temp;
		tree_height.push_back(temp);
	}

	sort(tree_height.begin(), tree_height.end());

	long long front = 0;
	long long back = tree_height.back();
	long long middle;
	long long answer = 0;


	while (front <= back)
	{
		middle = (front + back) / 2;
		long long sum = 0;

		for (auto c : tree_height)
		{
			if (middle < c)
			{
				sum += (c - middle);
			}
		}

		if (sum < M)
		{
			back = middle-1;
		}
		else if (sum >= M)
		{
			if (answer < middle)
			{
				answer = middle;
			}
			front = middle+1;
		}
	}
	cout << answer << endl;

	return 0;
}