#include <iostream>
#include <set>

using namespace std;

int main(void)
{
  // 입출력 속도 향상
  // C 표준 stream과 C++ 표준 stream 동기화 해제
	ios::sync_with_stdio(0);
  // cin을 cout으로부터 untie
  cin.tie(0);
	int N, M;
	int temp;
	// 이진 탐색 트리 이용
	set<int> bst;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		bst.insert(temp);
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> temp;
		// find()는 해당 값이 없으면 end()값 return
		if (bst.find(temp) == bst.end())
			cout << 0 << "\n";
		else if (bst.find(temp) != bst.end())
			cout << 1 << "\n";
	}

	return 0;
}