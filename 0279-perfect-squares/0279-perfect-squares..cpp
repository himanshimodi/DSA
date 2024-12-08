class Solution {
public:
    int solveRE(int n){
        //BC
        if(n==0) return 0;

        //ek case solve krdo
        int ans = INT_MAX;
        for(int i=1; i*i<=n;i++){
            int temp = i*i;
            ans = min(ans, 1+solveRE(n-temp));
        }
        return ans;
    }

    int solveMem(int n,vector<int> &dp){
        //BC
        if(n==0) return 0;

        //step 3
        if(dp[n]!=-1){
            return dp[n];
        }

        //ek case solve krdo
        int ans = INT_MAX;
        for(int i=1; i*i<=n;i++){
            int temp = i*i;
            ans = min(ans, 1+solveMem(n-temp,dp));
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        // int ans = solveRE(n);
        // return ans;

        vector<int> dp(n+1,-1);
        int ans = solveMem(n,dp);
        return ans;
    }
};