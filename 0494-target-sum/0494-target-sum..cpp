class Solution {
public:
    int solveRE(int i, int sum, int target, vector<int>&nums){
        //BC
         if (i == nums.size()) {
            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }

        //ek case
        //include
        int ans=0;
        ans+= solveRE(i+1, sum+nums[i],target,nums);
        //exclude
        ans+= solveRE(i+1, sum, target, nums);
        return ans;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        if((target+sum)%2 != 0) return 0;
        int p = (target+sum)/2;

        return solveRE(0, 0, p, nums);
    }
};