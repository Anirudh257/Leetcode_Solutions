// Time complexity: O(n^3), Space complexity: O(N) 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashSet;

        for (string s : wordDict) {
            hashSet.insert(s);
        }

        queue<int> q;
        q.push(0);
        int len = s.length();

        vector<bool> visited(len, false);

        while(!q.empty()) {
            int stInd = q.front();
            q.pop();

            if (visited[stInd]) {
                continue;
            }
            // Check for substrings of size 1, 2, ,... len
            for (int end = stInd + 1; end <= len; end++) {
                string sub = s.substr(stInd, end - stInd);
                if (hashSet.count(sub)) {
                    q.push(end);
                    if (end == len) {
                        return true;
                    }
                }
            }
            visited[stInd] = true;

        }

        return false;
    }
};
