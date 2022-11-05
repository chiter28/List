#include <iostream>


template<typename T>
class List {
public:
	List();
	void pop_front();
	void pop_back();
	void clear();
	void push_back(T data);
	void push_front(T data);
	void insert(T value, int index);
	void removeAt(int index);

	int GetSize() { return Size; }

	T& operator [] (const int index);

	~List();

private:
	template<typename T> class Node {
	public:
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}

		Node* pNext;
		T data;
	};

	int Size;
	Node<T>* head;
};



template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* tmp = head->pNext;
	delete head;
	head = tmp;
	Size--; 
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T value, int index)
{

	if (index == 0) {
		push_front(value);
	}
	else {
		Node<T>* prev = head;
		while (index - 1) {
			prev = prev->pNext;
			index--;
		}
		prev->pNext = new Node<T>(value , prev->pNext);
		Size++;
	}

}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* prev = head;
		while (index - 1) {
			prev = prev->pNext;
			index--;
		}
		Node<T>* toDelete = prev->pNext;
		prev->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
T& List<T>::operator [] (const int index)
{
	Node<T>* current = head;
	int cout = 0;
	while (current != nullptr) {
		if (cout == index) {
			return current->data;
		}
		current = current->pNext;
		cout++;
	}
}

template<typename T>
List<T>::~List()
{
	clear();
}










int main()
{
	List<int> lst;
	
	lst.push_back(4);
	lst.push_back(6);
	lst.push_back(46);
	std::cout << "Size: " << lst.GetSize() << std::endl;

	for (int i = 0; i < lst.GetSize(); i++) {
		std::cout << lst[i] << " ";
	}

	lst.pop_back();

	std::cout << "Size: " << lst.GetSize() << std::endl;

	for (int i = 0; i < lst.GetSize(); i++) {
		std::cout << lst[i] << " ";
	}


	


}

int f()
{
	return 1;
}