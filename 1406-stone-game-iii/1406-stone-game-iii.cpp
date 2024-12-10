class Solution {
public:
    int solveRE(vector<int>& stoneValue, int i) {
        // BC
        if (i == stoneValue.size()) {
            return 0;
        }

        // ek case solve krdo
        int ans = INT_MIN;
        int total = 0;
        // X is number of stones
        for (int X = 1; X <= 3; X++) {
            if (i + X - 1 >= stoneValue.size()) {
                break;
            }
            total += stoneValue[i + X - 1];
            ans = max(ans, total - solveRE(stoneValue, i + X));
        }
        return ans;
    }

    int solveMem(vector<int>& stoneValue, int i,vector<int>&dp) {
        // BC
        if (i == stoneValue.size()) {
            return 0;
        }

        //step 3
        if(dp[i]!=-1){
            return dp[i];
        }

        // ek case solve krdo
        int ans = INT_MIN;
        int total = 0;
        // X is number of stones
        for (int X = 1; X <= 3; X++) {
            if (i + X - 1 >= stoneValue.size()) {
                break;
            }
            total += stoneValue[i + X - 1];
            ans = max(ans, total - solveMem(stoneValue, i + X,dp));
        }
        dp[i] = ans;
        return dp[i];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // int ans = solveRE(stoneValue, 0);

        vector<int>dp(n+1,-1);
        int ans = solveMem(stoneValue, 0,dp);

        if (ans > 0)
            return "Alice";
        if (ans < 0)
            return "Bob";
        else
            return "Tie";
    }
};