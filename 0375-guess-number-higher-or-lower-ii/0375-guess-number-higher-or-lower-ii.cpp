class Solution {
public:
    int solveUsingRe(int start, int end){
        //base case
        if(start>=end){
            //range se bahar 
            //zero penalty
            return 0;
        }

        //ek case solve krdo
        int ans = INT_MAX;
        for(int i=start; i<=end; i++){
            ans = min(ans, i+ max(solveUsingRe(start, i-1), solveUsingRe(i+1, end)));
        }
        return ans;
    }

    int solveUsingMem(int start, int end, vector<vector<int>>&dp){
        //base case
        if(start>=end){
            //range se bahar 
            //zero penalty
            return 0;
        }

        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        int ans = INT_MAX;
        for(int i=start; i<=end; i++){
            ans = min(ans, i+ max(solveUsingMem(start, i-1,dp), solveUsingMem(i+1, end,dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }



    int getMoneyAmount(int n) {
        int start =1;
        int end  = n;

        // int ans = solveUsingRe(start,end);
        // return ans;

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingMem(start,end, dp);
        return ans;
    }
};