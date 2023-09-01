#include<iostream>
#include<set>

using namespace std;

// All operations: erase, insert, find, count take logarithmic time.
// unordered_set's operations are in O(1) time but worst case: O(n) time.

int main() {
    // Store elements in a sorted and unique order.
    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1, 2}
    st.emplace(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.emplace(3); // {1, 2, 3, 4}

    auto it = st.find(3); /// iterator to 3 if it exists else st.end()

    st.erase(3); // takes logarithmic time

    int cnt = st.count(1);
    

    return 0;
}