#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int num) {
		data = num;
		next = NULL;
	}
};

class Queue {
public:
	int size;
	Node* front;
	Node* rear;

	Queue() {
		front = NULL;
		rear = NULL;
	}

	bool Empty() {
		return (size == 0);
	}

	void enQueue(int num) {
		Node* temp = new Node(num);
		temp->data = num;
		temp->next = NULL;
		if (size == 0) {
			front = rear = temp;
			size++;
		}
		else {
			rear->next = temp;
			rear = temp;
			size++;
		}
	}

	void deQueue() {
		Node* temp = front;
		front = front->next;
		size--;
		delete temp;
	}

	int frontData() {
		return front->data;
	}

	int sizeData() {
		return size;
	}

	void print() {
		Node* temp = front;
		while (temp != NULL) {
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	Queue q;
	q.enQueue(1);
	q.print();
	q.enQueue(2);
	cout << q.sizeData() << endl;
	q.print();
	q.deQueue();
	q.print();
	q.deQueue();
	q.print();

	system("pause");
	return 0;
}