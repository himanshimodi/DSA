class Solution {
public:
    bool solveRE(int i, int sum, int target, vector<int>&nums){
        //BC
        if(i>=nums.size()){
            return false;
        }
        if(target < sum){
            return false;
        }
        if(sum == target){
            return true;
        }

        //ek case
        int inc = solveRE(i+1,sum+nums[i],target,nums);
        int exc = solveRE(i+1,sum,target,nums);

        return inc || exc;
    }

    bool memo(int i, int sum, int target, vector<int>&nums, vector<vector<int>>&dp){
        //BC
        if(i>=nums.size()){
            return false;
        }
        if(target < sum){
            return false;
        }
        if(sum == target){
            return true;
        }

        //step 3
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        //ek case
        int inc = memo(i+1,sum+nums[i],target,nums,dp);
        int exc = memo(i+1,sum,target,nums,dp);

        //step 2: store and return ans in dp
        dp[i][sum]= (inc||exc);
        return dp[i][sum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum, target;
        for(int i : nums){
            sum+=i;
        }
        target =sum /2;

        if(sum%2 == 1){
            return false;
        }
        // return solveRE(0, 0, target, nums);
        
        //step 1
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return memo(0,0,target,nums,dp);
    }
};