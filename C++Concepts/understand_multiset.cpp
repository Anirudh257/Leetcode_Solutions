#include<iostream>
#include<multiset>

using namespace std;

// Can store multiple occurences of a single character.

int main() {

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    ms.erase(1); // erase all 1s.

    int cnt = ms.count(1); // returns 3

    // erase only single 1
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(1) + 2);

    return 0;
}