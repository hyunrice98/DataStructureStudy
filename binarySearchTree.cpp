// binary search tree

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	Node* left;
	Node* right;
	Node(int num) {
		data = num;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

class BST {
private:
	Node* root;

public:
	BST() {
		root = NULL;
	}

	Node* search(Node* node, int num) {
		if (node == NULL || node->data == num) {
			return node;
		}
		if (node->data > num) {
			// pointer node's data is bigger than the input
			return search(node->left, num);
		}
		else {
			// pointer node's data is smaller than the input
			return search(node->right, num);
		}
	}

	void insertNode(int num) {
		Node* newNode = new Node(num);
		Node* current = root;
		Node* parent = NULL;

		// while loop for finding the leaf NULL spot
		while (current != NULL) {
			parent = current;
			if (current->data > num) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
		// if escape while, [current = NULL && parent = current->parent]

		newNode->parent = parent;

		// For finding exact place to insert Node
		if (parent == NULL) {
			// nothing is in the tree
			root = newNode;
		}
		else if (parent->data > newNode->data) {
			// parent data is bigger than inserted data
			parent->left = newNode;
		}
		else {
			// parent data is smaller than inserted data
			parent->right = newNode;
		}
	}

	// re-linking nodes
	void transPlant(Node* parent, Node* child) {
		// assign child node to parent node
		if (parent->parent == NULL) {
			// nothing is in the tree
			root = child;
		}
		else if (parent == parent->parent->left) {
			// if parent node is leftChild of the superior node
			parent->parent->left = child;
		}
		else {
			// if parent node is rightChild of the superior node
			parent->parent->right = child;
		}

		if (child != NULL) {
			child->parent = parent->parent;
		}
	}

	void deleteNode(int num) {
		// make node that has num
		Node* n = search(root, num);

		// 1) if node has no child
		if (n->left == NULL && n->right == NULL) {
			if (n->parent == NULL) {
				root = NULL;
			}
			else {
				if (n == n->parent->right) {
					n->parent->right = NULL;
				}
				else {
					n->parent->left = NULL;
				}
			}
		}
		
		// 2) if node has one child
		else if (n->left == NULL && n->right != NULL) {
			// node has right child
			transPlant(n, n->right);
		}
		else if (n->left != NULL && n->right == NULL) {
			// node has left child
			transPlant(n, n->left);
		}

		// 3) node has two children
		else {
			// make minNode, and right, leftleftleft...
			Node* minNode = n->right;
			while (minNode->left != NULL) {
				minNode = minNode->left;
			}

			if (minNode->parent != n) {
				transPlant(minNode, minNode->right);
				minNode->right = n->right;
				minNode->right->parent = minNode;
			}

			transPlant(n, minNode);
			minNode->left = n->left;
			minNode->left->parent = minNode;
		}
		delete n;
	}
};