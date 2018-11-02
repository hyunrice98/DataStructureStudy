// min priority queue using heap

#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
	vector<int> v;
	int heapSize;
	int rootIndex = 1;

public:
	Heap() {
		v.push_back(-1);
		heapSize = 0;
	}

	void _swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}

	void upHeap(int index) {
		if (index == rootIndex) { // if parameter input is root index, stop
			return;
		}

		int parent = index / 2; // parent index of input index node
		if (v[parent] > v[index]) {
			_swap(parent, index); // swap once
			upHeap(parent); 
		}
		else { // until parent is smaller than index
			return;
		}
	}

	void downHeap(int index) {
		int left = index * 2;
		int right = index * 2 + 1;

		if (right <= heapSize) {
			if (v[left] < v[right]) {
				if (v[left] < v[index]) {
					_swap(left, index);
					downHeap(left);
				}
				else return;
			}
			else {
				if (v[right] < v[index]) {
					_swap(right, index);
					downHeap(right);
				}
				else return;
			}
		}
		else {
			if (left <= heapSize) {
				if (v[left] < v[index]) {
					_swap(left, index);
				}
			}
			else return;
		}
	}

	void insert(int num) {
		v.push_back(num);
		heapSize++;
		upHeap(heapSize);
	}

	int removeMin() {
		int temp = v[1];
		v[1] = v[heapSize--];
		v.pop_back();
		downHeap(rootIndex);
		return temp;
	}

	void print() {
		for (int i = 1; i <= heapSize; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Heap h;
	int cmd;
	int tempNum;

	cin >> cmd;
	for (int i = 0; i < cmd; i++) {
		cin >> tempNum;
		h.insert(tempNum);
	}

	h.print();
	for (int i = 0; i < cmd; i++) {
		cout << h.removeMin() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}