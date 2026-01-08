class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        //step 1
        vector<vector<int>> dp(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // step 2: ek case solve karo (current pair lo)
                int curr = nums1[i] * nums2[j];
                dp[i][j] = curr;

                if (i > 0 && j > 0) {
                    dp[i][j] = max(dp[i][j], curr + dp[i-1][j-1]);
                }

                // nums1 ka element skip
                if (i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }

                // nums2 ka element skip
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        // step 3 (final): last cell me poora answer
        return dp[n-1][m-1];
    }
};