#include<iostream>
#include <vector>
#include<stack>
using namespace std;

// Time complexity: O(N), Space complexity: O(N + E), N = number of nodes,E = number of edges

class TopSort {
public:
	vector<int> compTopSort(vector<int> graph[], int N) {
		stack<int> st;
		vector<bool> visited(N, false); 
		vector<int> res;

		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				perfDFS(graph, i, visited, st);
			}
			st.push(i);
		}

		while(!st.empty()) {
			res.push_back(st.top());
			st.pop();
		}

		return res;
	}

private:
	void perfDFS(vector<int> graph[], int node, vector<bool>& visited, stack<int>& st) {
		visited[node] = true;

		for (int adj : graph[node]) {
			if (!visited[adj]) {
				perfDFS(graph, adj, visited, st);
			}
		}
		// st.push(node);

	}
};


int main() {
	int N = 5;
	vector<int> graph[N + 1];

	graph[2].push_back(3);
	graph[3].push_back(1);

	graph[4].push_back(0);
	graph[4].push_back(1);

	graph[5].push_back(0);
	graph[5].push_back(2);

	TopSort topSort;

	vector<int> topoSort = topSort.compTopSort(graph, N + 1);


	return 0;
}
