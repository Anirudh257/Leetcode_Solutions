#include<iostream>
#include<list>
using namespace std;

// Inserting in the front is faster than a vector as it is implemented in the doubly linked list fashion.

int main() {
    list<int> ls;

    ls.push_back(2); // 2
    ls.emplace_back(4); // {2, 4}

    ls.push_front(5); // {5, 2, 4} faster to do here than in the case of a vector.
    ls.emplace_front();

    return 0;
}