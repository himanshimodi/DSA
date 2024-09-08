class Solution {
public:
    int solveUsingMemo(vector<int>&nums, int i, vector<int>&dp){
        //base case
        if(i>=nums.size()){
            return 0;
        }

        //ans already exists
        if(dp[i] != -1){
            return dp[i];
        }

        //RE logic
        int include = nums[i] + solveUsingMemo(nums, i+2, dp);
        int exclude = 0 + solveUsingMemo(nums, i+1, dp);
        dp[i] = max(include, exclude);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        //creating a dp
        vector<int> dp(n, -1);
        return solveUsingMemo(nums, 0, dp);
    }
};