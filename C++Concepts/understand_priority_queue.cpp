#include<iostream>
#include<priority_queue>
#include<vector>

using namespace std;

// Internally stored in the tree fashion. push and pop - O(log n), top - O(1)

int main() {
    priority_queue<int> pq; // max heap -> max element at top of the queue.

    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top(); // 10

    pq.pop(); // {8, 5, 2}

    // Minimum heap - min element at the top of the queue.
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2, 5, 8}
    pq.emplace(10); // {2, 5, 8, 10}

    cout << pq.top(); // 2

    return 0;
}