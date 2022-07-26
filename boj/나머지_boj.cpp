#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0); 
	cin.tie(0);
	set<int> container;
	int temp;
	int sum = 0;

	for (int i = 0; i < 10; ++i)
	{
		cin >> temp;
		container.insert(temp%42);
	}
	
	cout << container.size() << "\n";

	return 0;
}