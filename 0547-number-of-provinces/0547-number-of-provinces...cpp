class Solution {
public:
    void dfs(int src, unordered_map<int,bool>&vis, int n, vector<vector<int>>& isConnected){
        vis[src]=true;

        //node row ke nbr nikalo
        int col=n;
        int row=src;
        for(int nbrIndex=0; nbrIndex<col; nbrIndex++){
            int nbr = nbrIndex;
            if(isConnected[row][nbrIndex]==1){
                if(vis[nbr]!=true){
                    dfs(nbr,vis,n, isConnected);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        unordered_map<int,bool>vis;
        int count = 0;
        for(int i=0; i<n; i++){
            if(vis[i]!=true){
                dfs(i,vis,n,isConnected);
                count++;
            }
        }
        return count;
    }

};