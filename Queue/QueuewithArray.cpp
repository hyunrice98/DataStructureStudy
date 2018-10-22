#include <iostream>
using namespace std;

class Queue {
public:
	int Arraysize;
	int* Array;
	int size; // how many data inside?
	int front;
	int rear;

	Queue() {
		*Array = Array[Arraysize];
		front = rear = 0;
	}
	Queue(int num) {
		Arraysize = num;
		Array = new int[Arraysize];
		front = rear = 0;
	}

	//enqueue, dequeue, front, size, empty, 
	int dataSize() {
		return size;
	}
	bool empty() {
		return size == 0;
	}
	int frontData() {
		return Array[front];
	}
	void enqueue(int num) {
		Array[rear%Arraysize] = num;
		rear++;
		size++;
	}
	void dequeue() {
		Array[front] = NULL;
		front++;
		size++;
	}
	void printQueue() {
		cout << "Queue Status : ";
		for (int cnt = front; cnt < rear; cnt++) {
			cout << Array[cnt] << " ";
		}
		cout << endl;
	}
};

int main() {
	Queue q(10);
	for (int i = 0; i < 10; i++) {
		q.enqueue(i);
	}
	q.printQueue();
	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.printQueue();

	system("pause");
	return 0;
}