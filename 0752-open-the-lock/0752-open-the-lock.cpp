class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Time complexity: 
        
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        
        if (deadSet.count("0000")) {
            return -1;
        }
        queue<string> q({"0000"});
        
        for (int numSteps = 0; !q.empty(); numSteps++) {
            for (int i = q.size(); i > 0; i--) {
                string curr = q.front();
                q.pop();
                
                if (curr == target) {
                    return numSteps;
                }
                
                for (auto nei : neighbors(curr)) {
                    if (deadSet.count(nei)) {
                        continue;
                    }
                    deadSet.insert(nei);
                    q.push(nei);
                }
            }
        }
        
        return -1;
    }
private:
    vector<string> neighbors(string& curr) {
        vector<string> res;
        for (int i = 0; i < 4; i++) {
            for (int diff = -1; diff <= 1; diff += 2) {
                string nei = curr;
                nei[i] = (nei[i] - '0' + diff + 10)%10 + '0';
                res.push_back(nei);
            }
        }
        return res;
    }
};