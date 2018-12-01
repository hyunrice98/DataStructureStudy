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

	Node* search(Node* node, int num) {
		// node has no data -> return Node with nothing inside
		// node's data matches num -> return the node
		if (node == NULL || node->data == num)
			return node;
		// node's data is bigger than input num
		// -> search with given data's left child as a new node input
		if (node->data > num)
			return search(node->left, num);
		// node's data is smaller than input num
		// -> search with given data's right child as a new node input
		else
			return search(node->right, num);
	}

	void bst_insert_iter(int num) {
		Node* newNode = new Node(num);
		Node* current = this->root;
		Node* parent = NULL;

		// until the current node is the external node,
		while (current != NULL) {
			// set parent as a current
			parent = current;
			// if given input is smaller than cursor(current)
			// -> set the cursor to the current's left child
			if (current->data > num)
				current = current->left;
			// if given input is bigger than cursor(current)
			// -> set the cursor to the current's right child
			else
				current = current->right;
		}
		newNode->parent = parent;

		// if parent is null, there is no node in the tree
		// -> set the newNode as root
		if (parent == NULL)
			this->root = newNode;
		// if given data is smaller than the external cursor
		// -> set parent's left child as a new node
		else if (parent->data > newNode->data)
			parent->left = newNode;
		// if given data is bigger than the external cursor
		// -> set parent's right child as a new node
		else
			parent->right = newNode;
	}

	// replace the parent node with child node
	void transplant(Node* parent, Node* child) {
		// if parent has no parent -> there is no node in the tree 
		// -> set root as child (there is no parent anyway)
		if (parent->parent == NULL)
			this->root = child;
		// covering parent with child node
		else if (parent == parent->parent->left)
			parent->parent->left = child;
		else
			parent->parent->right = child;
		// link covered node's parent as original parent's parent
		if (child != NULL)
			child->parent = parent->parent;
	}

	void bst_delete(int num) {
		// search the exact node which has num as data
		Node* n = search(this->root, num);
		/// the node has no child
		if (n->left == NULL && n->right == NULL) {
			if (n->parent == NULL) {
				this->root = NULL;
			}
			else {
				if (n == n->parent->right)
					n->parent->right = NULL;
				else
					n->parent->left = NULL;
			}
		}

		/// node has only one child
		// cover the only child to their parent
		else if (n->left == NULL && n->right != NULL)
			transplant(n, n->right);
		else if (n->left != NULL && n->right == NULL)
			transplant(n, n->left);

		/// node has both child
		else {
			// minnode is n's rightleftleftleft...(biggest of lesser than n)
			Node* minNode = n->right;
			while (minNode->left != NULL)
				minNode = minNode->left;

			// if the smallest node is not the deleted node's child
			if (minNode->parent != n) {
				transplant(minNode, minNode->right);
				minNode->right = n->right;
				minNode->right->parent = minNode;
			}
		}
		delete n;
	}

};