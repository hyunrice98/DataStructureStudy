// General Tree using vector

#include <iostream>
#include <vector>

using namespace std;

class Tree;

class Node {
private:
	int data;
	Node* parent;
	vector<Node*> children;

public:
	Node() {
		this->parent = NULL;
	}

	Node(int data) {
		this->data = data;
		this->parent = NULL;
	}

	void setParent(Node* parent) {
		this->parent = parent;
	}

	// push children into children member vector
	void insertChild(Node* children) { 
		this->children.push_back(children);
	}

	void deleteChild(Node* children) {
		// find particular children in the child vector
		for (int i = 0; i < this->children.size(); i++) {
			if (this->children[i] == children) {
				// erase found children(its in begin+i)
				this->children.erase(this->children.begin() + i);
			}
		}
	}

	friend Tree;
};

class Tree {
private:
	Node* root;
	// for size and search
	vector<Node*> nodeList;

public:
	Tree() {
		root = NULL;
	}

	Tree(int data) {
		// assign node including data into root
		root = new Node(data);
		// push assigned root into nodeList
		nodeList.push_back(root);
	}

	void insertNode(int parentData, int data) {
		Node* tempParent;
		// searching I in all the nodeList
		for (auto &i : this->nodeList) {
			// finding parentData in the nodeList
			if (i->data == parentData) {
				tempParent = i;
				Node* temp = new Node(data);
				// TEMPPARENT has new CHILDREN TEMP (pushed in stack)
				tempParent->insertChild(temp);
				// TEMP has new PARENT TEMPPARENT (linked together)
				temp->setParent(tempParent);
				nodeList.push_back(temp);
				return;
			}
		}
		return;
	}

	void deleteNode(int data) {
		Node* nowNode;
		Node* tempParent;
		// searching I in all the nodeList
		for (int i = 0; i < this->nodeList.size(); i++) {
			// if I is found,
			if (this->nodeList[i]->data == data) {
				nowNode = nodeList[i];
				// NOWNODE's PARENT node is TEMPPARENT
				tempParent = nowNode->parent;
				for (auto &child : nowNode->children) {
					// link every child node of nownode to tempParent
					tempParent->insertChild(child);
					child->setParent(tempParent);
				}
				// delete tempParent's child nowNode
				tempParent->deleteChild(nowNode);
				// nodeList's real node delete
				this->nodeList.erase(this->nodeList.begin() + i);
				delete nowNode;
			}
		}
	}

	void printChild(int num) {
		// find node
		for (auto &i : this->nodeList) {
			if (i->data == num) {
				if (i->children.size() == 0) {
					cout << "0";
				}
				// print all children node
				for (auto &child : i->children) {
					cout << child->data << " ";
				}
				cout << endl;
				return;
			}
		}
		cout << "-1" << endl;
	}

	int depth(int num) {
		// find node
		for (auto &i : this->nodeList) {
			if (i->data == num) {
				int counter = 0;
				// counter++ until i reaches root node
				while (i != this->root) {
					i = i->parent;
					counter++;
				}
				return counter;
			}
		}
	}
};