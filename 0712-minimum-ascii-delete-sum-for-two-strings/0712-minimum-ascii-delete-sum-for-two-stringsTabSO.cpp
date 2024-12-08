class Solution {
public:
    int solveRE(string& s1, string& s2, int i, int j) {
        int cost = 0;
        // BC
        if (i == s1.length()) {
            // s2 ke remaining characters add krdo
            for (int index = j; index <= s2.length(); index++) {
                cost += s2[index];
            }
            return cost;
        }
        if (j == s2.length()) {
            // s1 ke remaining characters add krdo
            for (int index = i; index <= s1.length(); index++) {
                cost += s1[index];
            }
            return cost;
        }

        // ek case solve krdo -> that is if chars match
        if (s1[i] == s2[j]) {
            cost += solveRE(s1, s2, i + 1, j + 1);
        } else { // chars dont match
            int cost1 = s1[i] + solveRE(s1, s2, i + 1, j);
            int cost2 = s2[j] + solveRE(s1, s2, i, j + 1);
            cost = min(cost1, cost2);
        }
        return cost;
    }

    int solveMem(string& s1, string& s2, int i, int j,
                 vector<vector<int>>& dp) {
        int cost = 0;
        // BC
        if (i == s1.length()) {
            // s2 ke remaining characters add krdo
            for (int index = j; index <= s2.length(); index++) {
                cost += s2[index];
            }
            return cost;
        }
        if (j == s2.length()) {
            // s1 ke remaining characters add krdo
            for (int index = i; index <= s1.length(); index++) {
                cost += s1[index];
            }
            return cost;
        }

        // step 3
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // ek case solve krdo -> that is if chars match
        if (s1[i] == s2[j]) {
            cost += solveMem(s1, s2, i + 1, j + 1, dp);
        } else { // chars dont match
            int cost1 = s1[i] + solveMem(s1, s2, i + 1, j, dp);
            int cost2 = s2[j] + solveMem(s1, s2, i, j + 1, dp);
            cost = min(cost1, cost2);
        }
        dp[i][j] = cost;
        return dp[i][j];
    }

    int solveTab(string& s1, string& s2) {
        vector<vector<int>> dp(s1.length() + 1,vector<int>(s2.length() + 1, 0));
        int cost = 0;

        // initialise base cases
        for (int row = s1.length() - 1; row >= 0; row--) {
            dp[row][s2.length()] = dp[row + 1][s2.length()] + s1[row];
        }
        for (int col = s2.length() - 1; col >= 0; col--) {
            dp[s1.length()][col] = dp[s1.length()][col + 1] + s2[col];
        }

        for (int i = s1.length() - 1; i >= 0; i--) {
            for (int j = s2.length() - 1; j >= 0; j--) {
                // ek case solve krdo -> that is if chars match
                if (s1[i] == s2[j]) {
                    cost = dp[i + 1][j + 1];
                } else { // chars dont match
                    int cost1 = s1[i] + dp[i + 1][j];
                    int cost2 = s2[j] + dp[i][j + 1];
                    cost = min(cost1, cost2);
                }
                dp[i][j] = cost;
            }
        }
        return dp[0][0];
    }

    int solveTabSO(string& s1, string& s2) {
        vector<int> currRow(s2.length() + 1, 0);
        vector<int> nextRow(s2.length() + 1, 0);
        int cost = 0;

        // initialise base cases
        
        for (int i = s2.length()-1; i >=0 ; i--) {
            nextRow[i] = nextRow[i + 1] + s2[i ]; 
        }

        for (int i = s1.length() - 1; i >= 0; i--) {
            currRow[s2.length()] = nextRow[s2.length() ] + s1[i];
            for (int j = s2.length() - 1; j >= 0; j--) {
                // ek case solve krdo -> that is if chars match
                if (s1[i] == s2[j]) {
                    cost = nextRow[j + 1];
                } else { // chars dont match
                    int cost1 = s1[i] + nextRow[j];
                    int cost2 = s2[j] + currRow[j + 1];
                    cost = min(cost1, cost2);
                }
                currRow[j] = cost;
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int minimumDeleteSum(string s1, string s2) {

        // int ans = solveRE(s1,s2,0,0);
        // return ans;

        // vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        // int ans = solveMem(s1,s2,0,0,dp);
        // return ans;

        // int ans = solveTab(s1,s2);
        // return ans;

        int ans = solveTabSO(s1, s2);
        return ans;
    }
};