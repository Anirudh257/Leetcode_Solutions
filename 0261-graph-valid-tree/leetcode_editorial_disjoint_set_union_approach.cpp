// Time complexity: O(N*alpha(N)), Space complexity: O(N)
class DSU {
private:
    vector<int> rank, root;
    int numComps;
public:
    DSU(int n) {
        rank.resize(n);
        root.resize(n);
        numComps = n;
        iota(root.begin(), root.end(), 0);
    }

    int findPar(int node) {
        if (node != root[node]) {
            root[node] = findPar(root[node]);
        }
        return root[node];
    }

    void Union(int x, int y) {
        int parX = findPar(x);
        int parY = findPar(y);

        if (parX != parY) {
            if (rank[parX] > rank[parY]) {
                root[parY] = parX;
            }
            else if (rank[parY] > rank[parX]){
                root[parX] = parY;
            }
            else {
                root[parY] = parX;
                rank[parX]++;
            }
            numComps--;
        }
    }

    int getNumComps() {
        return numComps;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int numEdges = edges.size();
        if (numEdges != n - 1) {
            return false;
        }      
        DSU uf(n);

        for (auto &x : edges) {
            uf.Union(x[0], x[1]);
        }

        return uf.getNumComps() == 1;
    }
};