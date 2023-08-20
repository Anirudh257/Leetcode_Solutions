#include<iostream>
#include<vector>

using namespace std;

// Time complexity: O(N), Space complexity: O(1)

vector<int> heapify(vector<int>& arr, int ind, int size) {
    int largeInd = ind;
    int left = 2*ind + 1;
    int right = 2*ind + 2;

    if (left < size && arr[left] > arr[largeInd]) {
        largeInd = left;
    }
    if (right < size && arr[right] > arr[largeInd]) {
        largeInd = right;
    }

    if (largeInd != ind) {
        int temp = arr[ind];
        arr[ind] = arr[largeInd];
        arr[largeInd] = temp;

        arr = heapify(arr, largeInd, size);
    }
    return arr;
}

int main() {
    vector<int> arr = {1, 14, 10, 8, 7, 9, 3, 2, 4, 6};
    int size = arr.size();


    // Only heapifying the internal/non-leaf nodes
    for (int i = size/2 - 1; i >= 0; i--) {
        arr = heapify(arr, i, size);
    }


    return 0;
}