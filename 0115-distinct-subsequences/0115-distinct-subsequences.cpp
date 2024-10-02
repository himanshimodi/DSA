class Solution {
public:
    int solveUsingRe(string s, string t, int n, int m, int i, int j) {
        // base case
        if (j == m) {
            return 1;
        }
        if (i == n) {
            return 0;
        }

        int ans = 0;
        // check for matching characters
        if (s[i] == t[j]) {
            ans = solveUsingRe(s, t, n, m, i + 1, j + 1) +
                  solveUsingRe(s, t, n, m, i + 1, j);
        } else {
            ans = solveUsingRe(s, t, n, m, i + 1, j);
        }

        return ans;
    }

    int solveUsingMem(string s, string t, int n, int m, int i, int j,
                      vector<vector<int>>& dp) {
        // base case
        if (j == m) {
            return 1;
        }
        if (i == n) {
            return 0;
        }

        // check if already stored
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        // check for matching characters
        if (s[i] == t[j]) {
            ans = solveUsingMem(s, t, n, m, i + 1, j + 1, dp) +
                  solveUsingMem(s, t, n, m, i + 1, j, dp);
        } else {
            ans = solveUsingMem(s, t, n, m, i + 1, j, dp);
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;

        // int ans = solveUsingRe(s, t, n, m, i, j);
        // return ans;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = solveUsingMem(s, t, n, m, i, j, dp);
        return ans;
    }
};