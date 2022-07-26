#include <iostream>

using namespace std;

int reverse(int x) 
{
	int ans = 0;

	for (int i = x;i;i /= 10)
		ans = ans * 10 + i % 10;

	return ans;
}


int main(void)
{
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int a, b;
	cin >> a >> b;

	a = reverse(a);
	b = reverse(b);

	if (a > b)
	{
		cout << a << "\n";
	}
	else
	{
		cout << b << "\n";
	}

	return 0;
}

