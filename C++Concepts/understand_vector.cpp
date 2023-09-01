#include<iostream>
#include<vector>

using namespace std;

int main() {

    vector<int> v;

    // emplace_back is faster than push_back as it doesn't create a new container before pushing into the memory.
    v.push_back(1);
    v.emplace_back(1);

    vector<pair<int, int>> vec;

    v.push_back({1, 2});
    v.emplace_back(1, 2); // automatically assumes than (1, 2) is of pair type

    vector<int> v(5);

    vector<int> v1(5, 20);
    vector<int> v2(v1); // make a separate copy of v1

    vector<int>::iterator it = v.end(); // points to the memory just after the last element of the vector v.

    vector<int>::iterator it = v.rend(); // points to the memory just before the 1st element of the vector v.

    vector<int>::iterator it = v.rbegin(); // points to the last element of the vector v and moves in a reverse fashion.

    // Erase

    // v = {10, 20, 12, 23} ---> // v = {10, 12, 23};
    v.erase(v.begin() + 1); 

    // v = {10, 20, 30, 40, 35} -- > {10, 20, 35} don't delete last index: v.begin() + 4 but delete everything before it.
    v.erase(v.begin() + 2, v.begin() + 4);

    // Insert
    vector<int> v(2, 100); // {100, 100}
    v.insert(v.begin(), 300); // {300, 100, 100}
    v.insert(v.begin() + 1, 2, 10); // Insert multiple elements at the position --> {300, 10, 10, 100, 100}

    vector<int> copy(2, 50);
    v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    return 0;
}