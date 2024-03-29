#define ALPHALEN 26
class Solution {
public:
    // Time complexity: O(V + E) to compute the indegree map + O(NC) to compare the characters between N pairs of 
    // words + O(V + E) for topological sort
    // Space complexity: O(V + E) for building a graph + O(V) for topological sort
    string alienOrder(vector<string>& words) {
        vector<int> adj[ALPHALEN];
        string valOrd = "";
        int n = words.size();
        unordered_map<int, int> indeg;
        
        for (auto &x : words) {
            for (char ch : x) {
                indeg[ch - 'a'] = 0;
            }
        }
        
        
        for (int i = 0; i < n - 1; i++) {
            string a = words[i];
            string b = words[i + 1];
            int len = min(a.length(), b.length());
            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {
                    adj[a[j] - 'a'].push_back(b[j] - 'a');
                    break;
                }
                
                if (j == len - 1 && a.size() > b.size()) {
                    return "";
                }
            }
        }
                
        valOrd = perfTopSort(adj, indeg);
        
        return valOrd;
    }
private:
    string perfTopSort(vector<int> adj[], unordered_map<int, int>& indeg) {
        queue<int> q;
        string valOrd = "";
        
        for (int i = 0; i < ALPHALEN; i++) {
            for (auto it : adj[i]) {
                indeg[it]++;
            }
        }
        
        
        
        for (auto &x : indeg) {
            if (x.second == 0) {
                q.push(x.first);
            }
        }
        
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            valOrd += char(top + 'a');
            
            for (auto neigh : adj[top]) {
                indeg[neigh]--;
                if (indeg[neigh] == 0) {
                    q.push(neigh);
                }
            }          
        }
        
        if (valOrd.size() != indeg.size()) {
            return "";
        }
        
        
        return valOrd;
    }
};