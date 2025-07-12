class Solution {
public:
    int solveRE(vector<int>& nums, int i, int &mini, int step){
        //BC
        if(i == nums.size()-1){
            mini = min(mini,step);
            return mini;
        }
        if(i >= nums.size()){
            return INT_MAX;
        }

        //ek case
        int ans =INT_MAX;
        for(int jump=1; jump<=nums[i];jump++){
            ans = min(ans,solveRE(nums,i+jump, mini, step+1));
        }
        return ans;
    }

    int memo(vector<int>& nums, int i, int &mini, int step,vector<vector<int>>&dp){
        //BC
        if(i == nums.size()-1){
            mini = min(mini,step);
            return mini;
        }
        if(i >= nums.size()){
            return INT_MAX;
        }

        //step 3
        if(dp[i][step]!=-1){
            return dp[i][step];
        }

        //ek case
        int ans =INT_MAX;
        for(int jump=1; jump<=nums[i];jump++){
            ans = min(ans,memo(nums,i+jump, mini, step+1,dp));
        }
        //step 2
        dp[i][step] = ans;
        return dp[i][step];
    }

    int tabulation(vector<int>& nums){
       int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0; // Base: already at end

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                if (dp[i + j] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i + j]);
            }
        }

        return dp[0];
    }
    
    int jump(vector<int>& nums) {
        int n= nums.size();
        int mini = INT_MAX;
        // return solveRE(nums,0,mini,0);

        //step 1
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return memo(nums,0,mini,0,dp);

        return tabulation(nums);
        
    }
};