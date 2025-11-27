#include<iostream>
#include<vector>

using namespace std;

// Time complexity: O(N*E, N = number of nodes, E = number of edges), Space complexity: O(N)

// Bellman Ford algorithm: Shortest path from any source node to all the other nodes when there is a
// negative edge cycle. Djikstra's can't detect a negative edge cycle but Bellman Ford algorithm is
// computationally more expensive.

struct Edge {
    int fir;
    int sec;
    int wt;

    Edge(int first, int second, int weight) {
        fir = first;
        sec = second;
        wt = weight;
    }
};

vector<int> relaxGraph(vector<Edge>& graph, int n, vector<int>& dist) {
    for (auto &edge : graph) {
        int u = edge.fir, v = edge.sec, w = edge.wt;
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
        }
    }
    return dist;
}

int main() {
    int N = 6, inf = 1e9, src = 0;

    vector<Edge> graph;
    graph.push_back(Edge(0, 1, 5));
    graph.push_back(Edge(1, 2, -2));
    graph.push_back(Edge(1, 5, -3));
    graph.push_back(Edge(2, 4, 3));
    graph.push_back(Edge(3, 2, 6));
    graph.push_back(Edge(3, 4, -2));
    graph.push_back(Edge(5, 3, 1));

    vector<int> dist(N, inf);

    dist[src] = 0;

    // Apply relaxation N - 1 times as N - 1 = maximum path distance from 1 node to the last
    for (int i = 0; i < N - 1; i++) {
        dist = relaxGraph(graph, N, dist);
    }

    vector<int> newDist = dist;

    newDist = relaxGraph(graph, N, newDist);

    if (newDist != dist) {
        cout << "Graph has negative edge cycle " << endl;
    }
    else {
        cout << "Shortest path from src " << src << " to all other nodes: " << endl;
        for (int i = 0; i < N; i++) {
            cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
        }
    }

    return 0;
}