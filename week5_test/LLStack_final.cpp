#include <iostream>
#include <string>
using namespace std;

// push, pop, size, top, empty

class Node {
public:
	int data;
	Node* next;
	Node(int num) {
		data = num;
		next = NULL;
	}
};

class Stack {
public:
	Node* head;
	Node* tail;
	int topNum; // top element's index number

	Stack() {
		head = NULL;
		tail = NULL;
		topNum = -1;
	}

	int size() {
		return topNum + 1;
	}

	bool empty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	int top() {
		if (empty()) {
			return -1;
		}
		else {
			return head->data;
		}
	}

	void push(int num) {
		if (empty()) {
			Node* temp = new Node(num);
			temp->data = num;
			temp->next = tail;
			head = temp;
			topNum++;
		}
		else {
			Node* temp = new Node(num);
			temp->data = num;
			temp->next = head;
			head = temp;
			topNum++;
		}
	}

	void pop() {
		if (empty()) {
			cout << "Stack is empty!" << endl;
		}
		else {
			Node* temp = head;
			cout << temp->data << endl;
			head = head->next;
			topNum--;
			delete temp;
		}
	}
};

int main() {
	int cmdNum;
	cin >> cmdNum;
	Stack s;

	while (cmdNum--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (cmd == "pop") {
			s.pop();
		}
		else if (cmd == "size") {
			cout << s.size() << endl;
		}
		else if (cmd == "top") {
			cout << s.top() << endl;
		}
		else if (cmd == "empty") {
			cout << (s.empty() ? 1 : 0);
		}
	}

	system("pause");
	return 0;
}