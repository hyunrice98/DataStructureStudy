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

class Tree {
private:
	Node* root;
public:
	Tree() {
		root = NULL;
	}

	Node* search(Node* node, int num) {
		// 재귀함수로 특정값 가지는 노드를 트리에서 찾기
		if (node == NULL || node->data == num)
			return node;
		if (node->data > num)
			return search(node->left, num);
		else
			return search(node->right, num);
	}

	void treeInsert(int num) {
		Node* newNode = new Node(num); // 삽입될 노드 생성
		Node* current = root; // root에서부터 값을 비교하여 들어갈 위치 찾음
		Node* parent = NULL;

		while (current != NULL) {
			parent = current;
			if (current->data > num)
				current = current->left;
			else
				current = current->right;
		}
		newNode->parent = parent; // 삽입되는 노드의 부모노드를 설정

		if (parent == NULL)
			root = newNode;
		else if (parent->data > newNode->data)
			parent->left = newNode;
		else
			parent->right = newNode;
	}

	void transPlant(Node* parent, Node* child) { // 노드 재연결하는 과정
		if (parent->parent == NULL)
			root = child;
		else if (parent == parent->parent->left)
			parent->parent->left = child;
		else
			parent->parent->right = child;

		if (child != NULL)
			child->parent = parent->parent;
	}

	void treeDelete(int num) {
		Node* n = search(root, num); // 삭제할 노드를 탐생

		if (n->left == NULL && n->right == NULL) { 
			// 자식 둘다 없을때
			if (n->parent == NULL) { // 부모 널값(삭제할노드 루트)이면 루트 삭제
				this->root = NULL;
			}
			else { 
				// 부모 널아니면(삭제할노드가 루트아님) 왼쪽오른쪽 방향결정
				if (n == n->parent->right) // 삭제노드가 부모의 오른쪽이면 오른쪽삭제
					n->parent->right = NULL;
				else // 삭제노드가 부모의 왼쪽이면 왼쪽삭제
					n->parent->left = NULL;
			}
		}
		else if (n->left == NULL && n->right != NULL) {
			// 오른쪽노드만 있다면
			transPlant(n, n->right);
		}
		else if (n->left != NULL && n->right == NULL) {
			// 왼쪽노드만 있다면
			transPlant(n, n->left);
		}
		else {
			// 두 자식 모두 있다면
			Node* minNode = n->right;
			while (minNode->left != NULL)
				minNode = minNode->left;

			if (minNode->parent != n) {
				// 가장 작은 값을 가지는 노드가 삭제할 노드의 자식이 아니라면
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