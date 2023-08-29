//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{// Time complexity: O(2^n), Space complexity: O(2^n)
public:
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> reqSubs;
        compSubSum(reqSubs, arr, 0, N, 0);
            
        return reqSubs;
    }
private:
    void compSubSum(vector<int>& reqSubs, vector<int>& arr, int ind, int N, int currSum) {
        if (ind == N) {
            reqSubs.push_back(currSum);
            return;
        }
        
        compSubSum(reqSubs, arr, ind + 1, N, currSum);
        compSubSum(reqSubs, arr, ind + 1, N, currSum + arr[ind]);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends