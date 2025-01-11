class Solution {
public:
    //Revision1
    void bfs(int src, vector<vector<int>>& isConnected, vector<bool>&vis){
        queue<int>q;
        //initial state
        q.push(src);
        vis[src] = true;

        //bfs chalao
        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            //check all nbr(cities) that are connected to this node(city)
            for(int nbr = 0; nbr < isConnected.size(); nbr++) {
                if(isConnected[currNode][nbr] && !vis[nbr]){
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        //number of traversals is my ans
        vector<bool>vis(isConnected.size(),false);
        int provinces=0;

        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                bfs(i,isConnected,vis);
                provinces++;
            }
        }
        return provinces;
    }
};