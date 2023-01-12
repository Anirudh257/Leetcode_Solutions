#include<iostream>
#include<algorithm>

using namespace std;
// Reference: https://www.youtube.com/watch?v=Cg7SI0WtmXY
// Lower and Upper bound work only for sorted arrays in O(log N), else they take O(N) time.

// lower bound = 3 cases:
    // a) If element is present, return the index of the element.
    // b) If element is not present, return the index of the element > element.
    // c) If the element is larger than all the present elements, returns Garbage values.

// upper bound
    // a) If the element is present/not present, return the index of the number > element.
    // b) If the element >= max(array elements), returns Garbage values.

// Different syntax for set/maps
// set<int> s;
// s.lower_bound(key);

int main() {
    int n = 6;
    int a[n] = {1, 4, 5, 5, 25, 7, 8};
    sort(a, a + n);

    cout << "Array elements are: " << endl;
    for (auto &x : a) {
        cout << x << " ";
    }
    cout << endl;

//    int* ptr = lower_bound(a, a + n, 5);// returns 5 as it is present
//    int *ptr = lower_bound(a, a + n, 6); // returns 7 as 7 > 6 and 1st element > 6 in the array
//    int *ptr = lower_bound(a, a + n, 26); // returns garbage value as 26 > max(a)

//    int *ptr = upper_bound(a, a + n, 1); // returns 4 as 4 > 1 and 1st element > 1 in the array
    int *ptr = upper_bound(a, a + n, 25); // returns not found as no element in array > 25
    if (ptr == (a + n)) {
        cout << "Not found in the array" << endl;
        return 0;
    }
    cout << (*ptr) << endl;

    return 0;
}
