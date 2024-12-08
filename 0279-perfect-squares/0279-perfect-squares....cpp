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

    int solveTab(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; 
        for (int i_index = 1; i_index <= n; i_index++) { //because in Memoization it is gng from n to zero like -> solveMem(n-temp,dp)
            for (int i = 1; i * i <= i_index; i++) {
                int temp = i * i;
                dp[i_index] = min(dp[i_index], 1 + dp[i_index - temp]);
            }
        }
        return dp[n];
    }


    int numSquares(int n) {
        // int ans = solveRE(n);
        // return ans;

        // vector<int> dp(n+1,-1);
        // int ans = solveMem(n,dp);
        // return ans;

        int ans = solveTab(n);
        return ans;
    }
};