class Solution {
public:
    
    // Time complexity: O(N), Space complexity: O(1)
    vector<int> replaceElements(vector<int>& arr) {
        int m=-1;
        for(int i=arr.size()-1;i>=0;i--) {
            int cur=arr[i];
            arr[i]=m;
            m=max(m, cur);
        }
        return arr;
    }    
};
