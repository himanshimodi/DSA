class Solution {
public:
    int solveRE(vector<vector<int>>& mat, int target, int sum, int row){
        if(row>=mat.size()){ //number of rows
            return abs(target-sum);
        }

        //ek case
        int ans=INT_MAX;
        for(int col=0;col<mat[0].size();col++){ //number of cols
            int reAns = solveRE(mat,target,sum+mat[row][col],row+1);
            ans = min(ans,reAns);
        }
        return ans;
    }

    int memo(vector<vector<int>>& mat, int target, int sum, int row, vector<vector<int>>&dp){
        if(row>=mat.size()){ //number of rows
            return abs(target-sum);
        }

        //step 3
        if( dp[sum][row] !=-1){
            return dp[sum][row];
        }

        //ek case
        int ans=INT_MAX;
        for(int col=0;col<mat[0].size();col++){ //number of cols
            int reAns = memo(mat,target,sum+mat[row][col],row+1,dp);
            ans = min(ans,reAns);
            dp[sum][row]= ans;
        }
        return dp[sum][row];
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int sum=0,row=0;
        int n = mat.size();
        // return solveRE(mat,target,sum,row);

        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            int rowMax = INT_MIN;
            for (int j = 0; j < mat[i].size(); j++) {
                rowMax = max(rowMax, mat[i][j]);
            }
            maxSum += rowMax;
        }

        //step 1
        vector<vector<int>>dp(maxSum+1,vector<int>(n+1,-1));
        return memo(mat,target,sum,row,dp);
    }
};