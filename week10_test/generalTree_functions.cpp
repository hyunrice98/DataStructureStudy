// general tree using vector
// 1.children print, 2.depth

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
	}

	friend Tree;
};

class Tree {
private:
	Node* root;
	vector<Node*> nodeList;
	int treeSize;

public:
	Tree() {
		root = NULL;
	}
	Tree(int num) {
		root = new Node(num);
	}

	void insertNode(int parentNum, int num) {
		Node* par;
		for (auto &i : nodeList) {
			if (i->data == parentNum) {
				par = i;
				Node* newNode = new Node(num);
				par->insertChild(newNode);
				newNode->setParent(par);
				nodeList.push_back(newNode);
				return;
			}
		}
		return;
	}

	void deleteNode(int num) {
		Node* nowNode;
		Node* par;
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->data == num) {
				nowNode = nodeList[i];
				par = nowNode->parent;
				for (auto &child : nowNode->children) {
					par->insertChild(child);
					child->setParent(par);
				}
				par->deleteChild(nowNode);
				nodeList.erase(nodeList.begin() + i);
				delete nowNode;
			}
		}
	}

	void printChild(int num) {
		for (auto &i : nodeList) {
			if (i->data == num) {
				if (i->children.size() == 0)
					cout << "0";
				for (auto &child : i->children) {
					cout << child->data << " ";
				}
				cout << endl; return;
			}
		}
	}

	int countDepth(int num) {
		Node* nowNode;
		int depth = 0;
		for (auto &i : nodeList) {
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
	}

};