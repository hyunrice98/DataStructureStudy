#include <iostream>
#include <vector>

#define M 50

using namespace std;

class vertex {
private:
	int degree;
public:
	vertex() {
		degree = 0;
	}
	void increase_deg() {
		degree++;
	}
	void decrease_deg() {
		degree--;
	}
};

class edge {
private:
	vertex* src;
	vertex* dst;
public:
	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
	}
};

class graph {
private:
	vertex** v;
	edge*** matrix;
	vector<edge*> e;
	int v_size;
	int max_size;
public:
	graph(int sz) {
		max_size = sz;
		v_size = 0;

		v = new vertex*[sz + 1];
		for (int i = 0; i < sz; i++)
			v[i] = NULL;

		matrix = new edge**[sz + 1];
		for (int i = 0; i < sz; i++) {
			matrix[i] = new edge*[sz + 1];
			for (int j = 0; j < sz; j++)
				matrix[i][j] = NULL;
		}
	}

	void insert_vertex(int n) {
		// no more space for vertex
		if (v_size + 1 > max_size)
			return;

		// more space left
		if (v[n] == NULL) {
			vertex* new_v = new vertex();
			v[n] = new_v;
			v_size++;
		}
		// there is already a vertex
		else {
			return;
		}
	}

	void erase_vertex(int n) {

	}

	void insert_edge(int src, int dst) {
		// if there is no vertex on side
		if (v[src] == NULL || v[dst] == NULL)
			return;
		// if there is already a edge
		if (matrix[src][dst] != NULL || matrix[dst][src] != NULL)
			return;

		// adding a edge in matrix
		edge* new_e = new edge(v[src], v[dst]);
		matrix[src][dst] = new_e;
		matrix[dst][src] = new_e;

		// degree increase in both vertex
		v[src]->increase_deg();
		v[dst]->increase_deg();

		// push in edge vector
		e.push_back(new_e);
	}

	void erase_edge(int src, int dst) {
		// if there is no such edge
		if (matrix[src][dst] == NULL || matrix[dst][src] == NULL)
			return;

		// decrease degree in both sides
		v[src]->decrease_deg();
		v[dst]->decrease_deg();


		for (int i = 0; i < e.size(); i++) {
			// delete edge in the stack if there is a edge in the matrix
			if (e[i] == matrix[src][dst] || e[i] == matrix[dst][src]) {
				e.erase(e.begin() + i);
				break;
			}
		}

		// deleting edge in the matrix
		matrix[src][dst] = NULL;
		matrix[dst][src] = NULL;
	}
};