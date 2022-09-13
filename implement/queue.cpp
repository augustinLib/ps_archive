#include <iostream>
#include <list>

template <class T>
class Queue
{
private:
//pop_front 이용하기 위해 vector가 아닌 연결리스트인 list 사용
	std::list<T> que;

public:
	Queue() {}
	//원소의 삽입
	void enqueue(const T& element)
	{
		que.push_back(element);
	}
	//원소의 삭제
	void dequeue()
	{
		que.pop_front();
	}
	// 큐 내부가 비어있는지 확인
	bool empty()
	{
		return que.empty();
	}
	// 큐의 front에 있는 원소 반환
	const T& front()
	{
		return que.front();
	}
	// 큐의 크기 확인
	int size()
	{
		return que.size();
	}
};

int main()
{
	Queue<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.dequeue();

	std::cout << q.front() << std::endl;
	q.enqueue(40);

	while (!q.empty()) {
		auto& e = q.front();
		std::cout << e << ", ";
		q.dequeue();
	}
	std::cout << std::endl;
}

