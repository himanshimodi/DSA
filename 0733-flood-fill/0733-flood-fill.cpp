class Solution {
public:
    bool isSafe(int newX, int newY, int sr, int sc,map<pair<int,int>,bool>&vis, vector<vector<int>> &ans, int oldColor){
        if (newX >= 0 && newX < ans.size() && newY >= 0 && newY < ans[0].size() && ans[newX][newY] == oldColor && vis[{newX, newY}]==false){ 
            return true;
        }
        else{
            return false;
        }
    }
    void dfs(int oldColor, int newColor, map<pair<int, int>, bool> &vis, vector<vector<int>> &ans,
             vector<vector<int>> &image, int sr, int sc){
        vis[{sr, sc}] = 1;
        ans[sr][sc] = newColor;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++){
            int newX = sr + dx[i];
            int newY = sc + dy[i];
            if (isSafe(newX, newY,sr,sc,vis,ans,oldColor)){
                dfs(oldColor, newColor, vis, ans, image, newX, newY);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> ans = image;
        int oldColor = image[sr][sc];
        int newColor = color;
        map<pair<int, int>, bool> vis;


        dfs(oldColor, newColor, vis, ans, image, sr, sc);
        return ans;
    }
};