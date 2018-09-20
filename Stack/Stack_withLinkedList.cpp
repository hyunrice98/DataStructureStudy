#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* nextNode;
	Node() {
		nextNode = NULL;
	}
	Node(int newData) {
		data = newData;
		nextNode = NULL;
	}
};

class Stack {
private:
	int count;
	Node* top;
public:
	Stack() {
		count = 0;
		top = NULL;
	}

	int Top() {
		if (top == NULL) {
			throw("stack is empty!");
		}
		else {
			return top->data;
		}
	}

	void push(int number) {
		count++;
		if (top == NULL) {
			Node* newNode = new Node(number);
			newNode->data = number;
			newNode->nextNode = NULL;
			top = newNode;
		}
		else {
			Node* newNode = new Node(number);
			newNode->data = number;
			newNode->nextNode = top;
			top = newNode;
		}
	}

	void pop() {
		if (top == NULL) {
			throw("stack is empty!");
		}
		else {
			count--;
			Node* temp = top;
			top = top->nextNode;
			delete temp;
		}
	}

	int size() {
		return count;
	}

	void print() {
		Node* temp = top;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->nextNode;
		}
	}
};