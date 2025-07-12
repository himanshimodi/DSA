class Solution {
public:
    void solve(int i, int j, int m, int n, vector<vector<int>>& grid, int sum, int &minSum) {
        //BC
        if(i == m-1 && j == n-1){
            sum += grid[i][j];  
            minSum = min(minSum, sum);
            return;
        }

        // ek case
        sum += grid[i][j];

        //RE
        if(j + 1 < n){
            solve(i, j + 1, m, n, grid, sum, minSum);
        }
        if(i + 1 < m){
            solve(i + 1, j, m, n, grid, sum, minSum);
        }

        return;
    }

    int memo(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>&dp) {
        int right=INT_MAX,down=INT_MAX;
        //BC
        if(i == m-1 && j == n-1){            
            return grid[i][j];
        }

        //step 3
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //step 2
        //RE
        if(j + 1 < n){
            right = memo(i, j + 1, m, n, grid, dp);
        }
        if(i + 1 < m){
            down = memo(i + 1, j, m, n, grid, dp);
        }
        dp[i][j] = grid[i][j] + min(right, down);
        return dp[i][j];
    }

    int tabulation(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        //step 1
        vector<vector<int>>dp(m,vector<int>(n,0));

        //step 2
        dp[m-1][n-1]=grid[m-1][n-1];

        for(int j=n-2;j>=0;j--){
            dp[m-1][j] = grid[m-1][j]+dp[m-1][j+1];
        }
        for(int i=m-2;i>=0;i--){
            dp[i][n-1] = grid[i][n-1]+dp[i+1][n-1];
        }

        //step 3
        for(int i = m-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }

        return dp[0][0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        // int m = grid.size();
        // int n = grid[0].size();
        // int minSum = INT_MAX;
        // int sum = 0;
        // solve(0, 0, m, n, grid, sum, minSum);
        // return minSum;
        
        //step 1
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return memo(0,0,m,n,grid,dp);

        return tabulation(grid);
    }
};
