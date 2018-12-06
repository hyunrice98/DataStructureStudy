#include <iostream>
#include <vector>

using namespace std;

class vertex {
private:
	int degree;
	char vertex_data;
	bool visited; // DFS통해 visit되었으면 true로 변경

public:
	vertex() {
		degree = 0;
		visited = false;
	}
	vertex(char data) {
		degree = 0;
		vertex_data = data;
		visited = false;
	}
	vertex(int deg, char data) {
		degree = deg;
		vertex_data = data;
		visited = false;
	}

	void increase_deg() {
		degree++;
	}
	void decrease_deg() {
		degree--;
	}

	void set_visited() { ///VISIT
		cout << vertex_data;
		visited = true;
	}
	bool get_visited() {
		return visited;
	}
};

class edge {
private:
	vertex* src;
	vertex* dst;
	bool explore; // 확인한 간선인지
	bool discovery;
	bool back;

public:
	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		explore = false;
		discovery = false;
		back = false;
	}
	bool get_explore() {
		return explore;
	}
	void set_explore() {
		explore = true;
	}
	bool get_discovery() {
		return discovery;
	}
	void set_discovery() { ///DIS
		discovery = true;
	}
	bool get_back() {
		return back;
	}
	void set_back() { ///BACK
		back = true;
	}
};

class graph {
private:
	vertex** v;
	edge*** matrix;
	vector<edge*> e;
	int v_sz;
	int max_sz;
public:
	graph(int sz) {
		this->max_sz = sz;
		this->v_sz = 0;

		this->v = new vertex*[sz];
		for (int i = 0; i < sz; i++)
			v[i] = NULL;

		this->matrix = new edge**[sz];
		for (int i = 0; i < sz; i++) {
			matrix[i] = new edge*[sz];
			for (int j = 0; j < sz; j++) {
				matrix[i][j] = NULL;
			}
		}
	}

	void insert_vertex(int n) {
		if (v_sz + 1 > max_sz)
			return;
		if (v[n] == NULL) {
			vertex* new_v = new vertex();
			v[n] = new_v;
			this->v_sz++;
		}
		else {
			return;
		}
	}
	// 1번문제용 overloaded function
	void insert_vertex(int n, char c) {
		if (v_sz + 1 > max_sz)
			return;
		if (v[n] == NULL) {
			vertex* new_v = new vertex(n, c);
			v[n] = new_v;
			this->v_sz++;
		}
		else {
			return;
		}
	}

	void insert_edge(int src, int dst) {
		if (v[src] == NULL || v[dst] == NULL)
			return; // 삽입될 edge양끝 vertex중 하나 없으면 종료
		if (matrix[src][dst] != NULL || matrix[dst][src] != NULL)
			return; // 이미 간선 존재하면 종료

		edge* new_e = new edge(v[src], v[dst]);
		matrix[src][dst] = new_e;
		matrix[dst][src] = new_e;

		v[src]->increase_deg();
		v[dst]->increase_deg();

		e.push_back(new_e);
	}

	void dfs(int start) {

		if (v[start]->get_visited() == true)
			return;

		v[start]->set_visited(); ///VISIT

		for (int i = 0; i < max_sz; i++) { // 인접행렬 기반 - 모든 행에 대해서 확인
			if (matrix[start][i] != NULL) {
				if (v[i]->get_visited() == false) { // 당므정점 visit안될때 수행
					matrix[start][i]->set_explore();
					matrix[start][i]->set_discovery(); ///DIS
					dfs(i);
				}
				else { // 이미 visit된 상태일때
					if (matrix[start][i]->get_discovery()) // discovery edge면 종료
						continue;
					else {
						matrix[start][i]->set_explore();
						matrix[start][i]->set_back(); ///BACK
						// 다음정점 visit이라 back edge설정
					}
				}
			}
		}
	}
};

int main() {
	graph g(500);
	int n;
	int m;
	int k;
	cin >> n >> m >> k;
	for (int ctr = 0; ctr < n; ctr++) {
		int i;
		char c;
		cin >> i >> c;
		g.insert_vertex(i, c);
	}
	for (int ctr = 0; ctr < m; ctr++) {
		int s;
		int d;
		cin >> s >> d;
		g.insert_edge(s, d);
	}
	g.dfs(k);

	system("pause");
	return 0;
}