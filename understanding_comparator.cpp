#include<iostream>
#include<vector>
#include<algorithm>
//#include<pair>

// Reference: https://www.youtube.com/watch?v=3pvZhwp0U9w

using namespace std;

//bool should_i_swap(int a, int b) {
//    if (a < b) {
//        return true;
//    }
//    return false;
//}

// In comparator, if we want to swap, return false, else return true;
// In return, just put what order you want to have as a result.
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    else {
        return a.second > b.second;
    }
}

// Sort in ascending order if a.first != b.first, else descending order
bool should_i_swap(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a > b;
    }
    else {
        return a < b;
    }
}



int main() {
    int n = 6;
    vector<pair<int, int>> a(n);

    a = {{4, 3},{5, 5},{5, 3}, {25, 6},  {7,9}, {8, 5}};

//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (should_i_swap(a[i], a[j])) {
//                swap(a[i], a[j]);
//            }
//        }
//    }

    sort(a.begin(), a.end(), cmp);

    for (auto &x : a) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}