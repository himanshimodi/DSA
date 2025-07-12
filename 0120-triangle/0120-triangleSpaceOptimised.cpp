class Solution {
public:
    int solveRE(vector<vector<int>>& triangle, int n, int row, int col){
        //BC
        if(row == n-1){
            return triangle[row][col];
        }

        //ek case
        int lower_left = triangle[row][col] + solveRE(triangle,n,row+1,col);
        int lower_right = triangle[row][col] + solveRE(triangle,n,row+1,col+1);

        return min(lower_left,lower_right);
    }

    int memo(vector<vector<int>>& triangle, int n, int row, int col, vector<vector<int>>&dp){
        //BC
        if(row == n-1){
            return triangle[row][col];
        }

        //step 3
        if( dp[row][col] != -1){
            return  dp[row][col];
        }

        //ek case
        int lower_left = triangle[row][col] + memo(triangle,n,row+1,col,dp);
        int lower_right = triangle[row][col] + memo(triangle,n,row+1,col+1,dp);

        //step 2
        dp[row][col] = min(lower_left,lower_right);
        return dp[row][col];
    }

    int tabulation(vector<vector<int>>& triangle){
        int n = triangle.size();
        //step 1
        vector<vector<int>>dp(n,vector<int>(n,-1));

        //step 2 : analyze base cases
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i= n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                //ek case
                int lower_left = dp[i+1][j];
                int lower_right =dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(lower_left,lower_right);
            }
        }
         
        
        return dp[0][0];
    }

    int tabulationSO(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<int>curr(n,0);
        vector<int>next(n,0);

        for(int j=0;j<n;j++){
            next[j] = triangle[n-1][j];
        }

        for(int i= n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                //ek case
                int lower_left = next[j];
                int lower_right =next[j+1];
                curr[j] = triangle[i][j] + min(lower_left,lower_right);
            }
            //shifting jo hum hamesha bhul jate hai
            next = curr;
        }
         
        
        return next[0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // return solveRE(triangle,n,0,0);

        //step 1
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return memo(triangle,n,0,0,dp);

        // return tabulation(triangle);

        return tabulationSO(triangle);

    }
};