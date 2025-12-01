#include<iostream>
#include<utility>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

// Time complexity: O(N+E)*logN, N = number of nodes, E = number of edges, log due to priority queue
// Space complexity: O(N+E) for adjacency list + O(E) for priority queue + O(N) for distance vector

struct cmp {
    constexpr bool operator()(
        pi const& a, pi const& b
    ) const noexcept {
        return a.first > b.first;
    }
};


vector<int> compDjikstra(vector<pi> adjList[], int N, int src) {
    vector<int> dist(N, 1e9);
    dist[src] = 0;
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push({0, src}); // dist, node, minHeap with minimum distance(node) on top

    while(!pq.empty()) {
        auto top = pq.top();
        int d = top.first;
        int elem = top.second;

        for (auto neigh : adjList[elem]) {
            int newNode = neigh.first;
            int wt = neigh.second;

            if (dist[newNode] > dist[elem] + wt) {
                dist[newNode] = dist[elem] + wt;
                pq.push({dist[newNode], newNode});
            }
        }
        pq.pop();
    }

    return dist;
}

int main() {
    int N = 6;
    vector<pi> adjList[N];
    adjList[1].push_back({2, 2});
    adjList[1].push_back({4, 1});

    // node, dist
    adjList[2].push_back({1, 2});
    adjList[2].push_back({5, 5});
    adjList[2].push_back({3, 4});

    adjList[3].push_back({2, 4});
    adjList[3].push_back({4, 3});
    adjList[3].push_back({5, 1});

    adjList[4].push_back({1, 1});
    adjList[4].push_back({3, 3});

    adjList[5].push_back({2, 5});
    adjList[5].push_back({3, 1});

    int src = 1;
    vector<int> dist = compDjikstra(adjList, N, src);

    cout << "The shortest distance from src " << src << " to other nodes is: " << endl;
    for (int i = 1; i < N; i++) {
        cout << "Distance from src " << src << " to node " << i << " " << dist[i] << endl;
    }

    return 0;
}