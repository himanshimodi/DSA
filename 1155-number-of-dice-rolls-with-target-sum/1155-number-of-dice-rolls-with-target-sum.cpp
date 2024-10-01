class Solution {
public:
    long long int MOD = 1000000007;
    int solveUsingRe(int n, int k, int target) {
        // base case
        if (target == 0 && n == 0) {
            return 1;
        }
        if (target != 0 && n == 0) {
            return 0;
        }
        if (target == 0 && n != 0) {
            return 0;
        }

        // ek case solve krdo
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += solveUsingRe(n - 1, k, target - i);
        }
        return ans;
    }

    int solveUsingMem(int n, int k, int target, vector<vector<int>>& dp) {
        // base case
        if (target == 0 && n == 0) {
            return 1;
        }
        if (target != 0 && n == 0) {
            return 0;
        }
        if (target == 0 && n != 0) {
            return 0;
        }

        // check if already stored
        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            int recAns = 0;
            if (target - i >= 0) {
                recAns = solveUsingMem(n - 1, k, target - i, dp) % MOD;
            }
            ans = (ans % MOD + recAns % MOD) % MOD;
        }
        // store ans
        dp[n][target] = ans;
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // int ans = solveUsingRe(n, k, target);
        // return ans;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = solveUsingMem(n, k, target, dp);
        return ans;
    }
};