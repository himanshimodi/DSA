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

    int solveUsingTab(int n){
        vector<vector<int>>dp(n+2, vector<int>(n+1, 0));
        for(int start = n; start>=1; start--){
            for(int end = 1; end<=n ; end++){

                //base case
                if(start>=end){
                    continue;
                }
                int ans = INT_MAX;
                for(int i= start; i<=end; i++){
                    ans = min(ans, i+max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        int start =1;
        int end  = n;

        // int ans = solveUsingRe(start,end);
        // return ans;

        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(start,end, dp);
        // return ans;

        int ans = solveUsingTab(n);
        return ans;
    }
};