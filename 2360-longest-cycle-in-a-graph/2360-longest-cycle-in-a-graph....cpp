class Solution {
public:
    void dfs(int node, vector<int>&edges, vector<int>&visited, vector<bool>&dfsTracker, vector<int>&dist, int currLen, int &longestCycleLen){
        if(node == -1){
            return;
        }
        visited[node] = true;
        dfsTracker[node] = true;
        dist[node] = currLen;

        int nextnode = edges[node];
        if(nextnode!=-1){
            if(!visited[nextnode]){
                dfs(nextnode, edges, visited, dfsTracker, dist, currLen+1, longestCycleLen);
            }
            else if(dfsTracker[nextnode]){
                //cycle is present
                int cycleLen = currLen - dist[nextnode] + 1;
                longestCycleLen = max(longestCycleLen, cycleLen);
            }
        }
        dfsTracker[node] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>dist(n,0); //to record distances
        vector<int>visited(n,0);
        vector<bool>dfsTracker(n,0);
        int longestCycleLen = -1;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,edges,visited,dfsTracker, dist, 0, longestCycleLen);
            }
        }
        return longestCycleLen;
    }
};