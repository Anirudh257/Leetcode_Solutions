#include<iostream>
#include<vector>

using namespace std;

// Reference: https://www.youtube.com/watch?v=VkKmmwzfIG4&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=6&ab_channel=Techdose

// Time complexity: O(N) [refer above linked video], Space complexity: O(logN)

vector<int> max_heapify(vector<int>& arr, int ind, int n) {
    // Recursively check that the subtree starting from arr[ind] is a heap
    // arr[ind] > left and arr[ind] > right subtrees and left and right subtrees should also be a heap
    int largest = ind;

    int left = 2*ind + 1;
    int right = 2*ind + 2;

    if (left < n && arr[left] > arr[ind]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != ind) {
        swap(arr[largest], arr[ind]);
        arr = max_heapify(arr, largest, n);
    }
    return arr;
}

vector<int> create_max_heap(vector<int>& arr, int n) {
    // Heap is a binary tree and can be represented in the form of array
    // So for a node i, left child is at 2*i + 1 and right child is at 2*i + 2
    // A tree of N nodes is of height logN, N/2 to N are leaf nodes and 0 to N/2 are internal nodes
    // A leaf node is already a max/min heap and hence we need to apply heapify operation from the last internal node
    // and go up to the root.
    for (int i = n/2 - 1; i >= 0; i--) {
        arr = max_heapify(arr, i, n);
    } 
    return arr;
}

int main() {

    vector<int> arr = {3, 6, 5, 0, 8, 2, 1, 9};
    int size = arr.size();

    arr = create_max_heap(arr, size);

    for (auto &x : arr) {
        cout << x << endl;
    }

    return 0;
}