// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int numWater = 0;
        int curr = 0, size = height.size();

        // curr = rightMost bound, stack: leftMostBound 
        while(curr < size) {
            while(!st.empty() && height[curr] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int dist = curr - st.top() - 1;
                int boundedHt = min(height[curr], height[st.top()]) - height[top];

                numWater += boundedHt*dist;
            }
            st.push(curr++);
        }

        return numWater;
    }
};
