// general tree using vector
// question 6-1 & 6-2

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

	void delChild(Node* chi) {
		for (int i = 0; i < children.size(); i++) {
			if (children[i] == chi) {
				children.erase(children.begin() + i);
				return;
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
	Tree(int data) {
		root = new Node(data);
		nodeList.push_back(root);
	}

	Node* getRoot() {
		return root;
	}

	void insertNode(int parentData, int data) {
		Node* par;
		for (auto &i : nodeList) { // linear search nodelist
			if (i->data == parentData) { // finding Node that match parentData
				Node* child = new Node(data); // child is data having Node
				par = i; // assign i(matching node) to par
				par->insertChild(child);
				child->setParent(par); // link par and child
				nodeList.push_back(child); // push child in the nodelist
				return;
			}
		}
		return;
	}

	void deleteNode(int num) {
		Node* nowNode;
		Node* par;
		for (int i = 0; i < nodeList.size(); i++) { // linear search nodelist
			if (nodeList[i]->data == num) { // find num
				nowNode = nodeList[i]; // link matching data to nownode
				par = nowNode->parent; // par is nownode's parent
				for (auto &child : nowNode->children) {
					//searching nownode's children(matching data's children)
					par->insertChild(child);
					child->setParent(par); // link all child with par
				}
				par->delChild(nowNode); // delete nownode from par
				nodeList.erase(nodeList.begin() + i); // erase nownode
				delete nowNode;
			} // end of if
		}
		return;
	}

	void printChild(int data) {
		for (auto &i : nodeList) {
			if (i->data == data) { // if data is found in nodelist
				if (i->children.size() == 0) {
					cout << "accroding data node has no child";
				}
				for (auto &child : i->children) { // print all child
					cout << child->data << " ";
				}
				cout << endl;
				return;
			}
		}
		cout << "node not found" << endl;
	}

	int depth(int num) {
		int depth = 0;
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->data == num) {
				Node* temp = nodeList[i];
				while (temp != root) {
					temp = temp->parent;
					depth++;
				}
			}
		}
		return depth;
	}

	void preOrder(Node* start) {
		cout << start->data << " ";
		for (auto &i : start->children) {
			preOrder(i);
		}
		return;
	}

	void postOrder(Node* start) {
		for (auto &i : start->children) {
			postOrder(i);
		}
		cout << start->data << " ";
		return;
	}
};

int main() {
	int nodeNum;
	Tree t(1);

	cin >> nodeNum;
	while (nodeNum--) {
		int nodeData;
		cin >> nodeData;

		while (true) {
			int childData;
			cin >> childData;
			if (childData == 0) {
				break;
			}
			t.insertNode(nodeData, childData);
		}
	}

	cout << "Preorder traversal of given tree\n : ";
	t.preOrder(t.getRoot());
	cout << "\nPostorder traversal of given tree\n : ";
	t.postOrder(t.getRoot());
	cout << endl;

	system("pause");
	return 0;
}