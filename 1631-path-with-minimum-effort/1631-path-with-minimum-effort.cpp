class Solution {
public:
    //Revision 1
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>>dist(row,vector<int>(col,INT_MAX));

        //maintain initial state
        pq.push({0,{0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto frontNode = pq.top();
            pq.pop();

            int currAbsDiff = frontNode.first;
            int x = frontNode.second.first;
            int y = frontNode.second.second;

            if(x == row-1 && y == col-1){
                //matlab reached dest
                return dist[x][y];
            }
            else{
                //else mai do up,down,left,right movement
                int dx[] = {0,-1,0,1};
                int dy[] = {1, 0,1,0};

                for(int i=0;i<4;i++){
                    int newX = x+dx[i];
                    int newY = y+dy[i];

                    //check if its safe
                    if(newX>=0 && newX<=row-1 && newY>=0 && newY<=col-1){
                        int newAbsDiff = abs(heights[x][y] - heights[newX][newY]); //abs diff MAXIMUM hona chaiye
                        int newMaxDiff = max(currAbsDiff,newAbsDiff); //efforts/dist MINIMUM store krna hai 

                        if(newMaxDiff < dist[newX][newY]){
                            dist[newX][newY] = newMaxDiff;
                            pq.push({newMaxDiff,{newX,newY}});
                        }
                    }
                }
            }
        }
        return 0;
    }

};