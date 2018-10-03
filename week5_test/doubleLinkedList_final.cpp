#include <iostream>
using namespace std;

class DNode {
public:
	int data;
	DNode* prev;
	DNode* next;
	DNode(int num) {
		data = num;
		prev = NULL;
		next = NULL;
	}
};

class DNode_List {
public:
	DNode* head;
	DNode* tail;
	DNode_List() {
		head = new DNode(-1);
		tail = new DNode(-1);
	}

	void insertNode(int num) {
		if (head->next == NULL) {
			DNode* temp = new DNode(num);
			temp->prev = head;
			temp->next = tail;
			head->next = temp;
			tail->prev = temp;
		}
		else {
			DNode* temp = new DNode(num);
			temp->prev = head;
			temp->next = head->next;
			head->next->prev = temp;
			head->next = temp;
		}
	}

	void deleteNode() {
		if (head->next == NULL) {
			cout << "No node in the list!" << endl;
		}
		else {
			DNode* temp = head->next;
			head->next = temp->next;
			temp->next->prev = head;
			delete temp;
		}
	}

	void print() {
		DNode* temp = head->next;
		while (temp != tail) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};

int main() {
	DNode_List DL;

	DL.deleteNode();
	cout << endl;

	DL.insertNode(1);
	DL.insertNode(2);
	DL.print();
	cout << endl;

	DL.insertNode(3);
	DL.insertNode(4);
	DL.print();
	cout << endl;

	DL.deleteNode();
	DL.print();
	cout << endl;

	system("pause");
	return 0;
}