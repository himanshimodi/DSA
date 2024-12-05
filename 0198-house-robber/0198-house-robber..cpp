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

    int solveUsingTabulation(vector<int>&nums){
        int n = nums.size();

        //step 1
        vector<int>dp (n, -1);

        //step 2 - initialisation
        dp[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){

            int tempAns =0;
            if(i+2 < n){
                tempAns = dp[i+2];
            }

            int include = nums[i] + tempAns;
            int exclude =0 + dp[i+1];
            dp[i] = max(include, exclude);
        }
        return dp[0];
    }

    int spaceOptimised(vector<int>& nums){
        int n = nums.size();

        //step 1
        vector<int> dp( n, -1);

        //step 2
        int prev = nums[n-1];
        int next = 0, curr;

        for(int i =n-1; i>=0; i--){

            int tempAns =0;
            if(i+2 < n){
                tempAns = next;
            }
            int include = nums[i] + tempAns;
            int exclude =0 + prev;
            curr = max(include, exclude);

            //dont forget updating
            next = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        // int n = nums.size();

        //creating a dp
        // vector<int> dp(n, -1);

        // return solveUsingMemo(nums, 0, dp);
        // int ans = solveUsingTabulation(nums);
        // return ans;

        return spaceOptimised(nums);
    }
};