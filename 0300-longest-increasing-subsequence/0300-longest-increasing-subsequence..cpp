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

    int solveUsingTab(vector<int> &nums){
        int n = nums.size();
        vector<vector<int>> dp (n+1, vector<int>(n+1, 0));

        for(int curr =n-1; curr>=0; curr--){
            for(int prev= curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr]> nums[prev]){
                    include = 1 +dp[curr+1][curr+1];//shifting prev
                }
                int exclude = 0;
                exclude = 0 + dp[curr+1][prev+1];//shifting prev

                dp[curr][prev+1] = max(include,exclude);
            }
        }
        return dp[0][0]; //initial values of curr=0 and prev = -1+1=0
    }

    int solveUsingTabSO(vector<int> &nums){
        int n = nums.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        
        for(int curr =n-1; curr>=0; curr--){
            for(int prev= curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr]> nums[prev]){
                    include = 1 +nextRow[curr+1];//shifting prev
                }
                int exclude = 0;
                exclude = 0 + nextRow[prev+1];//shifting prev
                currRow[prev+1] = max(include,exclude);
            }
            //updating
            nextRow = currRow;
        }
        return nextRow[0]; //initial values of curr=0 and prev = -1+1=0
    }

    //USING BINARY SEARCH
    int solveUsingBinarySearch(vector<int>& nums){
        vector<int>ans;
        ///initial state
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                //just bada number exist krta hai
                int index = lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin();
                //replace
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev =-1;
        int curr =0;
        int n = nums.size();

        // int ans = solveUsingRe(nums,curr, prev);
        // return ans;

        // vector<vector<int>> dp (n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(nums,curr,prev,dp);
        // return ans;

        // int ans = solveUsingTab(nums);
        // return ans;

        // int ans = solveUsingTabSO(nums);
        // return ans;

        int ans = solveUsingBinarySearch(nums);
        return ans;
    }
};
