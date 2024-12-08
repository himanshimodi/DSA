class Solution {
public:
    int solveRE(int n, vector<int>& days, vector<int>& costs, int i) {
        // base case
        if (i >= days.size()) {
            return 0;
        }
        // ek case solve krdo
        // 1 day pass
        int cost1 = costs[0] + solveRE(n, days, costs, i + 1);

        // 7 day pass
        int j;
        for (j = i; j < n && days[j] < days[i] + 7; j++);
        int cost7 = costs[1] + solveRE(n, days, costs, j);

        // 30 day pass
        int k;
        for (k = i; k < n && days[k] < days[i] + 30; k++);
        int cost30 = costs[2] + solveRE(n, days, costs, k);

        return min(cost1, min(cost7, cost30));
    }

    int solveMem(int n, vector<int>& days, vector<int>& costs, int i,vector<int>&dp) {
        // base case
        if (i >= days.size()) {
            return 0;
        }

        //step 3
        if(dp[i]!=-1){
            return dp[i];
        }
        // ek case solve krdo
        // 1 day pass
        int cost1 = costs[0] + solveMem(n, days, costs, i + 1,dp);

        // 7 day pass
        int j;
        for (j = i; j < n && days[j] < days[i] + 7; j++);
        int cost7 = costs[1] + solveMem(n, days, costs, j,dp);

        // 30 day pass
        int k;
        for (k = i; k < n && days[k] < days[i] + 30; k++);
        int cost30 = costs[2] + solveMem(n, days, costs, k,dp);

        int ans= min(cost1, min(cost7, cost30));
        dp[i]=ans;
        return dp[i];
    }

    int solveTab(int n, vector<int>& days, vector<int>& costs, int i) {
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;

        for(int index = n-1; index>=0; index--){
            // ek case solve krdo
            // 1 day pass
            int cost1 = costs[0] + dp[index + 1];

            // 7 day pass
            int j;
            for (j = index; j < n && days[j] < days[index] + 7; j++);
            int cost7 = costs[1] + dp[j];

            // 30 day pass
            int k;
            for (k = index; k < n && days[k] < days[index] + 30; k++);
            int cost30 = costs[2] + dp[k];

            int ans= min(cost1, min(cost7, cost30));
            dp[index]=ans;
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // return solveRE(n, days, costs, 0);

        // vector<int>dp(n+1,-1);
        // return solveMem(n, days, costs, 0,dp);

        return solveTab(n, days, costs, 0);
    }
};