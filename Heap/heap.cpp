#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
	vector<int> v;
	int heap_size;
	int root_index;

public:
	Heap() {
		v.push_back(-1);
		heap_size = 0;
	}

	void _swap(int index1, int index2) {
		v[0] = v[index1];
		v[index1] = v[index2];
		v[index2] = v[0];
	}

	void upHeap(int index) {
		if (index == root_index)
			return;

		int parent = index / 2;
		if (v[parent] < v[index]) {
			_swap(parent, index);
			upHeap(parent);
		}
		else {
			return;
		}
	}

	void downHeap(int index) {
		int left = index * 2;
		int right = index * 2 + 1;

		if (right <= heap_size) {
			if (v[left] > v[right]) {
				if (v[left] > v[index]) {
					_swap(left, index);
					downHeap(left);
				}
				else
					return;
			}
			else {
				if (v[right] > v[index]) {
					_swap(right, index);
					downHeap(right);
				}
				else
					return;
			}
		}
		else {
			if (left <= heap_size) {
				if (v[left] > v[index]) {
					_swap(left, index);
				}
			}
			else {
				return;
			}
		}
	}

	void insert(int num) {
		v.push_back(num);
		heap_size++;
		upHeap(heap_size);
	}

	int remove() {
		int ret = v[1];
		v[1] = v[heap_size--];
		v.pop_back();
		downHeap(root_index);
		return ret;
	}
};