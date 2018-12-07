#include <iostream>

using namespace std;

class Node {
public:
	Node* parent;
	Node* left;
	Node* right;
	int data;
	Node(int n) {
		parent = NULL;
		left = NULL;
		right = NULL;
		data = n;
	}
};

class BST {
private:
	Node* root;
public:
	BST() {
		root = NULL;
	}

	// node is starting point, num is data trying to find out
	Node* search(Node* node, int num) {
		if (node == NULL || node->data == num)
			return node;
		if (node->data > num)
			return search(node->left, num);
		else
			return search(node->right, num);
	}

	int bst_insert(int num) {
		Node* newNode = new Node(num); // node containing input data
		Node* current = root; // starting pointer
		Node* parent = NULL; // pointer2(currnet's parent)
		int c = 0;

		while (current != NULL) {
			c++;
			parent = current; // set parent
			if (current->data > num) // pointer's data is bigger than input
				current = current->left; // set pointer to left
			else // pointer's data is smaller than input
				current = current->right; // set pointer to right
		}
		newNode->parent = parent; //setting newNode's parent

		if (parent == NULL) // parent==NULL -> no node in BST -> set as root
			root = newNode;
		// parent data is bigger than input -> newNode as leftchild
		else if (parent->data > newNode->data)
			parent->left = newNode;
		// parent data is smaller than input -> newNode as rightchild
		else
			parent->right = newNode;

		return c;
	}

	// child node take over parent place
	void transplant(Node* parent, Node* child) {
		if (parent->parent == NULL)
			root = child;
		else if (parent == parent->parent->left)
			parent->parent->left = child;
		else
			parent->parent->right = child;

		if (child != NULL)
			child->parent = parent->parent;
	}

	void bst_delete(int num) {
		// n is node to be deleted
		Node* n = search(root, num);

		// n has no child
		if (n->left == NULL && n->right == NULL) {
			// n has no parent&child -> delete root
			if (n->parent == NULL) {
				this->root = NULL;
			}
			else {
				if (n == n->parent->right) // n exists as rightChild
					n->parent->right = NULL;
				else // n exist as leftChild
					n->parent->left = NULL;
			}
		}

		// if there is only one child
		else if (n->left == NULL && n->right != NULL) {
			transplant(n, n->right);
		}
		else if (n->left != NULL && n->right != NULL) {
			transplant(n, n->left);
		}

		// there are two child
		else {
			// set minnode to smallest node below n
			Node* minNode = n->right;
			while (minNode->left != NULL)
				minNode = minNode->left;

			// if minnode is not child of to be deleted node
			if (minNode->parent != n) {
				transplant(minNode, minNode->right);
				minNode->right = n->right;
				minNode->right->parent = minNode;
			}
			// replacing minNode with to be deleted node
			transplant(n, minNode);
			minNode->left = n->left;
			minNode->left->parent = minNode;
		}
		delete n;
	}
};

int main() {
	int cmdNum;
	BST t;
	cin >> cmdNum;
	int output = 0;
	for (int i = 0; i < cmdNum; i++) {
		int nodeData;
		cin >> nodeData;
		output += t.bst_insert(nodeData);
		cout << output << endl;
	}

	system("pause");
	return 0;
}