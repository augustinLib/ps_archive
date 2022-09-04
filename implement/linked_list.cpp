#include <iostream>

template <typename T>
struct Node
{
  // 이중 연결 리스트이기 때문에 data 앞뒤로 연결해주는 link로 node가 구성된다.
  T data;
  Node* prev;
  Node* next;
};

template <typename T>
class DoublyLinkedList
{
private:
  int count;
  Node<T>* header;
  Node<T>* trailer;

public:
  // 이중 연결 리스트 안에 iterator 추가
  class iterator
  {
    private:
      Node<T>* ptr;

    public:
      // 멤버 이니셜라이저를 이용한 멤버변수 ptr 초기화
		iterator() : ptr(NULL) {}
		iterator(Node<T>* p) : ptr(p) {}

      // 연산자 * 오버로딩
      // 데이터의 멤버변수를 참조 형태로 반환
      T& operator*() { return ptr->data; }

      // 연산자 ++ 오버로딩(prefix)
      iterator& operator++()
      {
        ptr = ptr->next;
        return *this;
      }

      // 연산자 -- 오버로딩(prefix)
      iterator& operator--()
      {
        ptr = ptr->prev;
        return *this;
      }
      
      // 연산자 == 오버로딩
      bool operator==(const iterator& it)
      {
        return ptr == it.ptr;
      }

      // 연산자 != 오버로딩
      bool operator!=(const iterator& it)
      {
        return ptr != it.ptr;
      }

      friend class DoublyLinkedList;
  };
  

  DoublyLinkedList()
  {
    // 멤버 변수 초기화
    count = 0;
    header = new Node<T> {T(), NULL, NULL};
    trailer = new Node<T> {T(), NULL, NULL};
    // header와 trailer를 이중으로 연결하여 초기화
    header->next = trailer;
    trailer->prev = header;
  }
  ~DoublyLinkedList()
  {
		while (!empty()) 
    {
			pop_front();
		}

		delete header;
		delete trailer;
  }

  iterator begin() const
  {
    return iterator(header->next);
  }

  iterator end() const
  {
    // iterator에서 end가 가리키는것은 맨 마지막 요소의 다음
    return iterator(trailer);
  }

  // pos가 가리키는 노드 앞에 val 값을 갖는 새로운 노드를 삽입
  void insert(const iterator& pos, const T& val)
  {
    Node<T>* p = pos.ptr;
    Node<T>* new_node = new Node<T> {val, p->prev, p};
    // new_node의 앞 노드의 next를 new_node를 가리키도록
    new_node->prev->next = new_node;
    //new_node 뒷 노드의 prev를 new_node를 가리키도록
    new_node->next->prev = new_node;
    count++;
  }

  void push_front(const T& val)
  {
    //iterator를 이용하여 맨 앞(header가 가리키는 node) 앞에 node 추가
    insert(begin(), val);
  }
  
  void push_back(const T& val)
  {
   //iterator를 이용하여 맨 뒤(trailer 뒤) 앞에 node 추가 
   insert(end(), val);
  }

  // pos가 가리키는 노드를 삭제
	void erase(const iterator& pos)
	{
		Node<T>* p = pos.ptr;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		count--;
	}

  void pop_front()
	{
		if (!empty())
			erase(begin());
	}

	void pop_back()
	{
		if (!empty())
			erase(--end());
	}

	iterator find(const T& val)
	{
		Node<T>* curr = header->next;

		while (curr->data != val && curr != trailer)
			curr = curr->next;

		return iterator(curr);
	}

	bool empty() const
	{
		return count == 0;
	}

	int size() const
	{
		return count;
	}
};