#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0); 
	cin.tie(0);
	vector<int> container;
	int temp;
	int sum = 0;

	for (int i = 0; i < 5; ++i)
	{
		cin >> temp;
		container.push_back(temp);
	}

	for (int c : container)
	{
		sum += pow(c, 2);
	}

	int result = sum % 10;
	cout << result << "\n";

	return 0;
}