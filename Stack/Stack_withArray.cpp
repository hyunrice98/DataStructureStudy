#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node(int data);
	Node() { this->data = 0; }
	~Node();
};

Node::Node(int data) {
	this->data = data;
}

Node::~Node() {
	cout << "node" << this->data << "deleted" << endl;
}

class Stack {
public:
	int capacity;
	int top;
	Node** nodes;

	Stack(int capacity);
	~Stack();

	void push(int data);
	int pop();
	bool isEmpty();
	int getSize();
};

Stack::Stack(int capacity) {
	this->nodes = new Node*[capacity];
	this->capacity = capacity;
	this->top = 0;
}

Stack::~Stack() {
	for (int i = 0; i < this->capacity; i++) {
		if (this->nodes[i]) {
			delete this->nodes[i];
		}
	}
	delete[] this->nodes;
}

void Stack::push(int data) {
	this->nodes[this->top++] = new Node(data);
	cout << "Push: " << data << endl;
}

int Stack::pop() {
	int data = this->nodes[--(this->top)]->data;
	cout << "Pop: " << data << endl;
	return data;
}

bool Stack::isEmpty() {
	return (this->top == 0);
}

int Stack::getSize() {
	return this->top - 1;
}

void STACK::display() /*function to Display elements in the stack*/
{
if(top==-1)
cout<<"\n\t\t\t      STACK UNDERFLOW!!!";
else
cout<<"\nElements in STACK are: ";
for(int i=top;i>=0;i--)
{
cout<<" "<<data[i];
}
getch();
}
int main() {
	Stack stack(30);
	stack.push(1);
	stack.push(2);
	stack.push(3);

	cout << "size: " << stack.getSize() << endl;

	stack.pop();
	stack.pop();

	cout << "empty: " << (stack.isEmpty() ? "true" : "false") << endl;

	stack.pop();

	cout << "empty: " << (stack.isEmpty() ? "true" : "false") << endl;

	return 0;
}
