// Time complexity: O(N), Space complexity: O(N)
class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        
        if (len % 2 != 0) {
            return false;
        }
        
        stack<char> st;
        
        for (char ch : s) {
            if (st.empty()) {
                st.push(ch);
            }
            else {
                char stTop = st.top();
                if (stTop == '(' && ch == ')') {
                    st.pop();
                }
                else if (stTop == '[' && ch == ']') {
                    st.pop();
                }
                else if (stTop == '{' && ch == '}') {
                    st.pop();
                }
                else {
                    st.push(ch);
                }
            }
        }
        
        return st.empty();
    }
};