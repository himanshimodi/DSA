class Solution {
public:

    int solveUsingRe(vector<int>&nums, int curr, int prev){
        //base case
        if(curr>=nums.size()){
            return 0;
        }

        int include = 0;
        if(prev == -1 || nums[curr]> nums[prev]){
            include = 1 + solveUsingRe(nums,curr+1,curr);
        }
        int exclude = 0;
        exclude = 0 + solveUsingRe(nums,curr+1,prev);

        int ans = max(include,exclude);
        return ans;
    }

    int solveUsingMem(vector<int>&nums, int curr, int prev, vector<vector<int>>&dp){
        //base case
        if(curr>=nums.size()){
            return 0;
        }

        //check if already exists
        if(dp[curr][prev+1]!= -1){
            return dp[curr][prev+1];
        }

        int include = 0;
        if(prev == -1 || nums[curr]> nums[prev]){
            include = 1 + solveUsingMem(nums,curr+1,curr,dp);
        }
        int exclude = 0;
        exclude = 0 + solveUsingMem(nums,curr+1,prev,dp);

        dp[curr][prev+1] = max(include,exclude);
        return dp[curr][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev =-1;
        int curr =0;

        // int ans = solveUsingRe(nums,curr, prev);
        // return ans;

        int n = nums.size();
        vector<vector<int>> dp (n+1, vector<int>(n+1, -1));
        int ans = solveUsingMem(nums,curr,prev,dp);
        return ans;
    }
};
