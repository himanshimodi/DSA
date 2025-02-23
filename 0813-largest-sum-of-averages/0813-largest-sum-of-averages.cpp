






You said:
class Solution {

private:
    double solve(int i, int k, vector<int>& nums, vector<int>& prefix, vector<vector<double>>& dp) {
        int n = nums.size();

        if(i == n) return 0.0;
        if(k == 0) return -1e7;

        if(dp[i][k] != -1.0) return dp[i][k];

        double maxi = 0.0;

        for(int ind = i; ind < n; ind++) {
            int sum = prefix[ind] - (i > 0 ? prefix[i-1] : 0);
            double avg = (double)sum/(double)(ind-i+1);

            maxi = max(maxi, avg + solve(ind+1, k-1, nums, prefix, dp));
        }

        return dp[i][k] = maxi;
    }

public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        // parition dp

        int n = nums.size();

        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        vector<vector<double>> dp(n, vector<double>(k+1, -1.0));

        return solve(0, k, nums, prefix, dp);
    }
};