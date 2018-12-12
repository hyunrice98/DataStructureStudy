#include <iostream>
#include <algorithm>
#include <vector>

#define div 353333
#define div2 17

using namespace std;

class item {
public:
	int value;
	int key;
	item() {}
	item(int k, int v) {
		key = k;
		value = v;
	}
};

class hash_array {
private:
	bool* flag;
	item* data;

public:
	hash_array(int sz) {
		flag = new bool[sz + 1];
		data = new item[sz + 1];
	}

	int hash_code(int key) {
		return key % div;
	}

	void linear_probing(int k, int v) {
		int index = hash_code(k);
		int i = index;

		while (flag[i] == true) {
			if (data[i].key == k) {
				data[i].value = v;
				return;
			}
			i = (i + 1) % div;
			if (i == index)
				return;
		}
		flag[i] = true;
		item ins(k, v);
		data[i] = ins;
	}

	int linear_search(int k, int v) {
		item* ret = NULL;
		int index = hash_code(k);
		int i = index;
		int probeNum = 0;

		do {
			probeNum++;
			if (data[i].key == k) {
				cout << "1 ";
				return probeNum;
			}
			i = (i + 1) % div;
			if (i == index)
				break;
		} while (flag[i] == true);

		cout << "0 ";
		return probeNum;
	}

	int hash_code_2(int key) {
		return div2 - key % div2;
	}

	void double_hashing(int k, int v) {
		int code1 = hash_code(k);
		int code2 = hash_code(k);
		int i = code1;

		while (flag[i] == true) {
			if (data[i].key == k) {
				data[i].value = v;
				return;
			}
			i = (i + code2) % div;
			if (i == code1)
				return;
		}
		flag[i] = true;
		item ins(k, v);
		data[i] = ins;
	}

	item* double_hashing_search(int k, int v) {
		item* ret = NULL;
		int code1 = hash_code(k);
		int code2 = hash_code_2(k);
		int i = code1;

		while (flag[i] == true) {
			if (data[i].key == k) {
				if (data[i].value == v) {
					ret = &data[i];
					break;
				}
			}
			i = (i + code2) % div;
			if (i == code1)
				break;
		}
		return ret;
	}
};

int main() {
	int n;
	int m;
	cin >> n;
	hash_array h(100000);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		h.double_hashing(num, num);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int searchNum;
		cin >> searchNum;
		if (h.double_hashing_search(searchNum, searchNum)) {
			cout << "1\n";
		}
		else
			cout << "0\n";
	}

	system("pause");
	return 0;
}