#include <iostream>
#include <vector>

using namespace std;

class vertex {
private:
	int degree;
	bool visited;
public:
	vertex() {
		degree = 0;
		visited = false;
	}
	void increase_deg() {
		degree++;
	}
	void decrease_deg() {
		degree--;
	}

	void set_visited() {
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
	bool explore;
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

	void set_explore() {
		explore = true;
	}
	bool get_explore() {
		return explore;
	}

	void set_discovery() {
		discovery = true;
	}
	bool get_discovery() {
		return discovery;
	}

	void set_back() {
		back = true;
	}
	bool get_back() {
		return back;
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
		max_sz = sz;
		v_sz = 0;

		v = new vertex*[sz];
		for (int i = 0; i < sz; i++)
			v[i] = NULL;

		matrix = new edge**[sz];
		for (int i = 0; i < sz; i++) {
			matrix[i] = new edge*[sz];
			for (int j = 0; j = sz; j++)
				matrix[i][j] = NULL;
		}
	}

	void insert_vertex(int n) {
		// if more vertex can't be inserted, return
		if (v_sz + 1 > max_sz)
			return;

		if (v[n] == NULL) {
			vertex* new_v = new vertex();
			v[n] = new_v;
			v_sz++;
		}
		// if there is already a vertex in that place, return
		else
			return;
	}

	void insert_edge(int src, int dst) {
		// if there is no vertex on each side of the edge, return
		if (v[src] == NULL || v[dst] == NULL)
			return;
		// if there is already a edge in that place, return
		if (matrix[src][dst] != NULL || matrix[dst][src] != NULL)
			return;

		edge* new_e = new edge(v[src], v[dst]);
		matrix[src][dst] = new_e;
		matrix[dst][src] = new_e;

		v[src]->increase_deg();
		v[dst]->increase_deg();

		e.push_back(new_e);
	}

	void dfs(int start) {
		// if starting point is visited already, return
		if (v[start]->get_visited() == true)
			return;

		// set starting point visited
		v[start]->set_visited();

		// loop all the node starting from 'start'point
		for (int i = 0; i < max_sz; i++) {
			// if node points something
			if (matrix[start][i] != NULL) {
				// and pointed vertex is not visited
				// set that node as explored and discovered
				// + another dfs loop at the end of node's vertex
				if (v[i]->get_visited() == false) {
					matrix[start][i]->set_explore();
					matrix[start][i]->set_discovery();
					dfs(i);
				}
				// if pointed vertex of the node is visited
				else {
					// and that node is already discovered, skip and do other node
					if (matrix[start][i]->get_discovery() == true)
						continue;
					// if the node is not discovered, set the node as explored and BACK
					else {
						matrix[start][i]->set_explore();
						matrix[start][i]->set_back();
					}
				}
			}
		}
	}
};