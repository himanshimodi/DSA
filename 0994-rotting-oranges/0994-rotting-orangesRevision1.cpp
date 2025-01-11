class Solution {
public:
    //Revision 1 
    bool isSafe(int newX, int newY, vector<vector<int>> &temp){
        if (newX >= 0 && newX < temp.size() && newY >= 0 && newY < temp[0].size() && temp[newX][newY] == 1){ 
            return true;
        }
        else{
            return false;
        }
    }

    int orangesRotting(vector<vector<int>> &grid){   
        queue<pair<pair<int, int>, int>> q;
        //pair->corrds and second member is minTime
        vector<vector<int>> temp = grid;
        int minTime = 0;
        int n = grid.size();
        int m = grid[0].size();

        // Find all rotten oranges and put them in the queue
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (temp[i][j] == 2){
                    //src node ka time 0 set krre hai
                    q.push({{i, j}, 0});
                }
            }
        }

        // BFS logic
        while (!q.empty()){
            auto frontNode = q.front();//pair access krre hai
            q.pop();

            auto frontNodePair = frontNode.first;
            int frontTime = frontNode.second;

            int tempX = frontNodePair.first;//accesssing x coordinate
            int tempY = frontNodePair.second;//accessing y coordinate

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++){
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];
                if (isSafe(newX, newY,temp)){
                    q.push({{newX, newY}, frontTime + 1});
                    // Mark this orange as rotten
                    temp[newX][newY] = 2;
                    minTime = max(minTime, frontTime + 1);
                }
            }
        }

        //jitne oranges rotten krne the kr liye now check if any fresh orange is left
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (temp[i][j] == 1){ 
                    return -1;
                }
            }
        }
        return minTime;
    }
};