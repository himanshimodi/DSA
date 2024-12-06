class Solution {
public:
    bool solveUsingRe(vector<int>& arr, int index, int sum, int target) {
        // base case
        if (index >= arr.size()) {
            return false;
        }
        if (sum > target) {
            return false;
        }
        if (sum == target) {
            return true;
        }
        // include exclude ek case solve krdo
        int include = solveUsingRe(arr, index + 1, sum + arr[index], target);
        int exclude = solveUsingRe(arr, index + 1, sum, target);

        return include || exclude;
    }

    // 2D DP
    bool solveUsingMem(vector<int>& arr, int index, int sum, int target,
                       vector<vector<int>>& dp) {
        // base case
        if (index >= arr.size()) {
            return false;
        }
        if (sum > target) {
            return false;
        }
        if (sum == target) {
            return true;
        }

        // check if already stored
        if (dp[index][sum] != -1) {
            return dp[index][sum];
        }
        // include exclude ek case solve krdo
        int include =
            solveUsingMem(arr, index + 1, sum + arr[index], target, dp);
        int exclude = solveUsingMem(arr, index + 1, sum, target, dp);

        dp[index][sum] = (include || exclude);
        return dp[index][sum];
    }

    bool solveUsingTab(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(target + 1, 0));

        for (int row = 0; row <= nums.size(); row++) {
            dp[row][target] = 1;
        }

        for (int index = n - 1; index >= 0; index--) {
            for (int sum = target; sum >= 0; sum--) {
                bool include = 0;
                if(sum + nums[index] <= target){
                    include = dp[index+1][sum + nums[index]];
                }
                bool exclude = dp[index+1][sum];
                dp[index][sum] = (include || exclude);
            }
        }
        return dp[0][0]; //index kaha se start kiya = first 0 
                         // sum kaha se start kiya = second 0
    }

    bool solveUsingTabSO(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int>curr(target+1, 0);
        vector<int>next(target+1, 0);

        curr[target] =1;
        next[target] =1;

        for (int index = n - 1; index >= 0; index--) {
            for (int sum = target; sum >= 0; sum--) {
                bool include = 0;
                if(sum + nums[index] <= target){
                    include = next[sum + nums[index]];
                }
                bool exclude = next[sum];
                curr[sum] = (include || exclude);
            }
            //updating
            next = curr;
        }
        return next[0];
    }

    bool canPartition(vector<int>& nums) {
        // pattern of coin change is used- that is include exclude pattern
        int index = 0;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        if (totalSum & 1) {
            // odd cannot be partitioned
            return false;
        }
        int target = totalSum / 2;
        int currSum = 0;
        int n = nums.size();

        // bool ans = solveUsingRe(nums,index,currSum,target);
        // return ans;

        // vector<vector<int>> dp(n+1, vector<int>(target+1 , -1));
        // bool ans = solveUsingMem(nums,index,currSum,target,dp);
        // return ans;

        // bool ans = solveUsingTab(nums,target);
        // return ans;

        bool ans = solveUsingTabSO(nums,target);
        return ans;
    }
};