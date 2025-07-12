class Solution {
public:
    bool solveRE(vector<int>& nums, int i){
        //BC
        if(i == nums.size()-1){
            return true;
        }
        if(i >= nums.size()){
            return false;
        }
        if(nums[i]==0){ //ab jump  he nhi kr sakta
            return false;
        }

        //ek case
        bool ans = false;
        for(int jump=1; jump<=nums[i];jump++){
            ans = ans || solveRE(nums,i+jump);
        }
        return ans;
    }

    bool memo(vector<int>& nums, int i, vector<int>&dp){
        //BC
        if(i == nums.size()-1){
            return true;
        }
        if(i >= nums.size()){
            return false;
        }
        if(nums[i]==0){ //ab jump  he nhi kr sakta
            return false;
        }

        //step 3
        if(dp[i]!=-1){
            return dp[i];
        }

        //ek case
        bool ans = false;
        for(int jump=1; jump<=nums[i];jump++){
            ans = ans || memo(nums,i+jump,dp);
        }
        //step 2
        dp[i] = ans;
        return dp[i];
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // return solveRE(nums,0);

        //step 1
        vector<int>dp(n,-1);
        return memo(nums,0,dp);
    }
};