#include<iostream>
#include<vector>
using namespace std;

// Time complexity: O(N^2), Space complexity: O(1)

// In-place algorithm, not stable.

class SelectionSort {
public:
    void selSort(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int minPos = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minPos]) {
                    minPos = j;
                }
            }
            swap(arr[i], arr[minPos]);
        }

        return;
    }
};

int main() {
    vector<int> arr = {6, 4, 1, 2, 4, 8};

    cout << "Array before sorting " << endl;
    for (auto &x : arr) {
        cout << x << " ";
    }
    cout << endl;

    SelectionSort ssort;
    ssort.selSort(arr);

    cout << "Array before sorting " << endl;
    for (auto &x : arr) {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}
