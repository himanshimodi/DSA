//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool checkCyclic(int src, unordered_map<int,bool>& vis, unordered_map<int,bool>& dfsTrack, vector<int> adj[], int safeNodes[]) {
        vis[src] = true;
        dfsTrack[src] = true;
        safeNodes[src] = 0;

        for (auto nbr : adj[src]) {
            if (!vis[nbr]) {
                bool ans = checkCyclic(nbr, vis, dfsTrack, adj, safeNodes);
                if (ans == true) {
                    return true;
                }
            } 
            // If the node is visited and still in the current DFS track
            else if (dfsTrack[nbr] == true) {
                return true;
            }
        }

        // Backtrack
        dfsTrack[src] = false;
        safeNodes[src] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int,bool> vis;         // Correct declaration
        unordered_map<int,bool> dfsTrack;    // Correct declaration
        int safeNodes[V] = {0};

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                checkCyclic(i, vis, dfsTrack, adj, safeNodes);
            }
        }

        for (int i = 0; i < V; i++) {
            if (safeNodes[i] == 1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends