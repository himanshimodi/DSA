class Solution {
public:
    bool RE(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    //MEMOIZATION
    bool Mem(int i, int j, string &s, vector<vector<int>>& dp) {
        if (i >= j) return true;  // Base case: Single character or empty substring

        if (dp[i][j] != -1) return dp[i][j];  // Use memoization if available

        if (s[i] == s[j]) {
            return dp[i][j] = Mem(i + 1, j - 1, s, dp);
        }
        dp[i][j] = false;
        return dp[i][j];
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string ans = "";

        // Extract all substrings
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (Mem(i, j, s, dp)) {
                    string t = s.substr(i, j - i + 1);  // Store palindromic substring in t
                    if (t.size() > ans.size()) {
                        ans = t;
                    }
                }
            }
        }

        return ans;
    }
};