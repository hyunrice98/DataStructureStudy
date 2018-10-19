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
		parent = NULL;
	}
	Node(int num) {
		data = num;
		parent = NULL;
	}
	void setParent(Node* par) {
		parent = par;
	}
	void insertChild(Node* chi) {
		children.push_back(chi);
	}
	void deleteChild(Node* chi) {
		for (int i = 0; i < children.size(); i++) {
			if (children[i] == chi) {
				children.erase(children.begin() + i);
			}
		}
		return;
	}
	friend Tree;
};

class Tree {
private:
	Node* root;
	vector<Node*> nodeList;
public:
	Tree() {
		root = NULL;
	}
	Tree(int num) {
		root = new Node(num);
		nodeList.push_back(root);
	}
	void setRoot(int data) {
		root = new Node(data);
		nodeList.push_back(root);
	}
	Node* getRoot() {
		return root;
	}
	void insertNode(int parentData, int num) {
		Node* tempParent;
		if (root == NULL) {
			cout << "There is no parent Node!" << endl;
		}
		else {
			for (auto &i : this->nodeList) {
				if (i->data == parentData) {
					tempParent = i;
					Node* newNode = new Node(num);
					tempParent->insertChild(newNode);
					newNode->setParent(tempParent);
					nodeList.push_back(newNode);
				}
			}
		}
	}
	void deleteNode(int num) {
		Node* nowNode;
		Node* tempParent;
		for (int i = 0; i < this->nodeList.size(); i++) {
			if (this->nodeList[i]->data == num) {
				nowNode = nodeList[i];
				if (nowNode == root) {
					cout << "Root can't be deleted" << endl;
				}
				tempParent = nowNode->parent;
				for (auto &child : nowNode->children) {
					tempParent->insertChild(child);
					child->setParent(tempParent);
				}
				tempParent->deleteChild(nowNode);
				this->nodeList.erase(this->nodeList.begin() + i);
				delete nowNode;
			}
		}
		return;
	}
	void printChild(int num) {
		for (auto &i : this->nodeList) {
			if (i->data == num) {
				if (i->children.size() == 0) {
					cout << "no children";
				}
				for (auto &child : i->children) {
					cout << child->data << " ";
				}
				cout << endl;
				return;
			}
		}
		cout << "Node can't be found" << endl;
	}
	int depth(int num) {
		Node* nowNode;
		int depth = 0;
		for (auto &i : this->nodeList) {
			if (i->data == num) {
				nowNode = i;
				while (true) {
					if (nowNode == root)
						return depth;
					nowNode = nowNode->parent;
					depth++;
				}
			}
		}
		return depth;
	}
	void preOrder(Node* startPoint) {
		cout << "Preorder : ";
		cout << startPoint->data << " ";
		for (auto &v : startPoint->children) {
			preOrder(v);
		}
	}
	void postOrder(Node* startPoint) {
		cout << "Postorder : ";
		for (auto &v : startPoint->children) {
			postOrder(v);
		}
		cout << startPoint->data << " ";
	}
};