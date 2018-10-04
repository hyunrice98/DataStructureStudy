#include <iostream>
using namespace std;

class Queue {
public:
	int* space;
	int frontIndex;
	int rearIndex;
	int capacity;

	Queue(int capacityNum) {
		space = new int[capacityNum];
		capacity = capacityNum;
		frontIndex = 0;
		rearIndex = -1;
	}
	int size() {
		return rearIndex + 1;
	}
	bool empty() {
		return rearIndex - frontIndex < 0;
	}
	int& front() {
		if (empty()) {
			cout << "Queue is empty!" << endl;
		}
		else {
			return space[frontIndex];
		}
	}
	int& rear() {
		if (empty()) {
			cout << "Queue is empty!" << endl;
		}
		else {
			return space[rearIndex];
		}
	}
	void enQueue(int num) {
		if (size() == capacity) {
			cout << "Queue is full!" << endl;
		}
		else {
			space[++rearIndex] = num;
		}
	}
	void deQueue() {
		if (empty()) {
			cout << "Queue is empty!" << endl;
		}
		++frontIndex;
	}
};

int main() {
	Queue a(10);
	a.enQueue(1);
	a.enQueue(2);
	cout << a.front() << " " << a.rear() << endl;
	a.enQueue(3);
	a.deQueue();
	cout << a.front() << " " << a.rear() << endl;
	a.deQueue();
	cout << a.front() << " " << a.rear() << endl;

	system("pause");
	return 0;
}