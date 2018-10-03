#include <iostream>
using namespace std;

class SNode {
public:
	int data;
	SNode* next;
	SNode(int num) {
		data = num;
		next = NULL;
	}
};

class Single_LinkedList {
public:
	SNode* head;
	SNode* tail;

	Single_LinkedList() {
		head = NULL;
		tail = NULL;
	}

	void insertNode(int num) {
		if (head == NULL) {
			SNode* newNode = new SNode(num);
			newNode->data = num;
			newNode->next = tail;
			head = newNode;
		}
		else {
			SNode* newNode = new SNode(num);
			newNode->data = num;
			newNode->next = head;
			head = newNode;
		}
	}

	void deleteNode() {
		if (head == NULL) {
			cout << "there is no node in the list!" << endl;
		}
		else {
			SNode* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void print() {
		SNode* temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};

int main() {
	Single_LinkedList SL;

	SL.insertNode(1);
	SL.insertNode(2);
	SL.print();
	cout << endl;

	SL.insertNode(3);
	SL.insertNode(4);
	SL.print();
	cout << endl;

	SL.deleteNode();
	SL.print();

	system("pause");
	return 0;
}