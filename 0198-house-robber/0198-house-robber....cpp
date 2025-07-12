class Solution {
public:
    int solve(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }

        int inc = nums[i] + solve(nums, i + 2);
        int exc = 0+ solve(nums, i + 1);
        
        return max(inc,exc);
    }

    int memo(vector<int>& nums, int i, vector<int>&dp) {
        //BC
        if (i >= nums.size()) {
            return 0;
        }
        //step 3: check if dp is already initialised
        if(dp[i]!=-1){
            return dp[i];
        }

        //ek case
        int inc = nums[i] + memo(nums, i + 2,dp);
        int exc = 0+ memo(nums, i + 1,dp);
        //step 2 : store and return dp
        dp[i]= max(inc,exc);
        return dp[i];
    }

    int tabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0);
        //BC
        dp[n]=0;
        dp[n-1]= nums[n-1];
        int inc =0,exc=0;

        for(int i=n-2;i>=0;i--){
            //ek case
            inc = nums[i] + dp[i+2];
            exc = 0+ dp[i+1];
            dp[i]= max(inc,exc);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums, 0);

        // step 1
        // vector<int>dp(n+1,-1);
        // return memo(nums,0,dp);

        return tabulation(nums);
    }
};
