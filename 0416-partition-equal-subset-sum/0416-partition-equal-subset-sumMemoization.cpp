class Solution {
public:

    bool solveUsingRe(vector<int>& arr,int index, int sum, int target){
        //base case
        if(index>=arr.size()){
            return false;
        }
        if(sum>target){
            return false;
        }
        if(sum == target){
            return true;
        }
        //include exclude ek case solve krdo
        int include = solveUsingRe(arr, index+1, sum+arr[index], target);
        int exclude = solveUsingRe(arr, index+1, sum, target);

        return include || exclude ;
    }

    //2D DP
    bool solveUsingMem(vector<int>& arr,int index, int sum, int target, vector<vector<int>>&dp){
        //base case
        if(index>=arr.size()){
            return false;
        }
        if(sum>target){
            return false;
        }
        if(sum == target){
            return true;
        }

        //check if already stored
        if(dp[index][sum]!= -1){
            return dp[index][sum];
        }
        //include exclude ek case solve krdo
        int include = solveUsingMem(arr, index+1, sum+arr[index], target,dp);
        int exclude = solveUsingMem(arr, index+1, sum, target,dp);

        dp[index][sum] = (include || exclude);
        return  dp[index][sum];
    }

    bool canPartition(vector<int>& nums) {
        // pattern of coin change is used- that is include exclude pattern 
        int index =0;
        int totalSum =0;
        for(int i=0; i<nums.size();i++){
            totalSum += nums[i];
        }
        if(totalSum & 1){
            //odd cannot be partitioned
            return false;
        }
        int target = totalSum/2;
        int currSum =0;
        int n = nums.size();
        
        // bool ans = solveUsingRe(nums,index,currSum,target);
        // return ans;

        vector<vector<int>> dp(n+1, vector<int>(target+1 , -1));
        bool ans = solveUsingMem(nums,index,currSum,target,dp);
        return ans;
    }
};