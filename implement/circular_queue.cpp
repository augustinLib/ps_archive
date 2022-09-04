#include <iostream>

#define MAXIMUM_QUEUE 8

template <class T>
class CircularQueue
{
private:
	T* arr;
	int front_index;
	int rear_index;
	int count; //현재 원소의 개수
	int capacity; // queue에 넣을 수 있는 원소의 개수
public:
	CircularQueue(int size = MAXIMUM_QUEUE) // 큐 초기화
	{
		arr = new T[size];
		front_index = 0;
		rear_index = -1; // 초기화 시 rear값은 -1 (원소가 추가되었을 때 front와 rear가 값은 값이기 위해)
		count = 0;
		capacity = size;
	}
	~CircularQueue()
	{
		delete [] arr; //동적 할당된 배열을 소멸자에서 해제
	}

	void enqueue(const T& element)
	{
		if(full()) // 큐가 가득 찬 상태에서 enqueue 진행 시 경고문구 출력과 종료
		{
			std::cout << "Overflow" << std::endl;
			return;
		}
		rear_index = (rear_index+1) % capacity; // rear가 원형 큐를 여러번 돌아도 첫 순환과 같은 위치를 가리키도록 함
		arr[rear_index] = element; // 원소 삽입
		count++; //원소 개수 추가
	}

	void dequeue()
	{
		if (empty()) // 큐가 비어있는 상태에서 dequeue 진행 시 경고문구 출력과 종료
		{
			std::cout << "Underflow" << std::endl;
			return;
		}

		front_index = (front_index + 1) % capacity; // front가 원형 큐를 여러번 돌아도 첫 순환과 같은 위치를 가리키도록 함
		count--;
	}

	const T& front() const 
	{
		return arr[front_index];
	}

	bool empty() const 
	{
		return count == 0;
	}

	int full() const 
	{
		return count == capacity;
	}

	int size() const
	{
		return count;
	}
};
using namespace std;

int main()
{
	CircularQueue<int> q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);  // full 상태
	q.dequeue();
	q.dequeue();    // 원소 2개 삭제
	q.enqueue(60);
	q.enqueue(70);  // full 상태
	q.enqueue(80);  // 오버플로우 에러!

	while (!q.empty()) {
		auto& e = q.front();
		cout << e << ", ";
		q.dequeue();
	}
	cout << endl;
}
