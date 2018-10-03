#include <iostream>
using namespace std;

class Stack {
private:
	int* space;
	int capacity;
	int topNum;
public:
	Stack() {
		space = new int[100];
		capacity = 100;
		topNum = -1;
	}
	Stack(int cap)
	{
		space = new int[cap];
		capacity = cap;
		topNum = -1; // top element's index number (0 for first one)
	}

	int size() // returns the number of elements in the stack
	{
		return topNum + 1;
	}

	bool empty() // returns 1 if there is no element in the stack
	{
		return topNum < 0;
	}

	int top()
	{
		if (empty()) {
			cout << "Stack is empty!" << endl;
		}
		else {
			return space[topNum];
		}
	}

	void push(int num) {
		if (size() == capacity) {
			cout << "Stack is full!" << endl;
		}
		else {
			space[++topNum] = num;
		}
	}

	void pop() {
		if (empty()) {
			cout << "Stack is empty!" << endl;
		}
		--topNum;
	}

	void print() {
		for (int cnt = 0; cnt < topNum + 1; cnt++) {
			cout << space[cnt] << " ";
		}
		cout << endl;
	}
};

int main() {
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.print();
	s.pop();
	s.print();

	system("pause");
	return 0;
}