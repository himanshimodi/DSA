class Solution {
public:
    int solveRE(int i, vector<int>& cost){
        //BC
        if(i>=cost.size()){
            return 0;
        }

        //ek case
        int op1=solveRE(i+1,cost);
        int op2=solveRE(i+2,cost);

        return cost[i]+min(op1,op2);
    }

    int memo(int i, vector<int>& cost,vector<int>&dp){
        //BC
        if(i>=cost.size()){
            return 0;
        }

        //step 3
        if(dp[i]!=-1){
            return dp[i];
        }

        //ek case
        dp[i]= cost[i]+min(memo(i+1,cost,dp),memo(i+2,cost,dp));
        return dp[i];
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        // int op1 = solveRE(0,cost);
        // int op2 = solveRE(1,cost);

        //step 1
        vector<int>dp(n+1,-1);
        int option1 = memo(0,cost,dp);
        int option2 = memo(1,cost,dp);
        return min(option1,option2);
    }
};