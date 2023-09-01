#include<iostream>
#include<queue>

using namespace std;

// All operations are O(1)

int main() {
    queue<int> q;

    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.emplace(4); // {1, 2, 4}

    q.back() += 5; // {1, 2, 9}

    q.front(); // prints 1

    q.pop(); // pop from the front: {2, 9}

    cout << q.front(); // prints 2

    return 0;
}