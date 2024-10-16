class Solution {
public:
    //this is kruskals algo
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (rank[u] < rank[v]) {
            parent[u] = v;
            rank[v]++;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // need to find number of connected components and no of extra edges
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int extraEdges = 0;
        for (auto connection : connections) {
            int u = connection[0];
            int v = connection[1];

            u = findParent(parent, u);
            v = findParent(parent, v);

            if (u != v) {
                unionSet(u, v, parent, rank);
            } else {
                extraEdges++;
            }
        }
        int nocc = 0; // no of connected components
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                nocc++;
            }
        }
        int ans = nocc - 1; // ans= no. of operations needed
        return extraEdges >= ans ? ans : -1;
    }
};