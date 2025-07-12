class Solution {
public:
    void solve(vector<int>& nums, int i, int ans, int& maxi) {
        if (i >= nums.size()) {
            maxi = max(maxi, ans);
            return;
        }

        solve(nums, i + 2, ans + nums[i], maxi); // include
        solve(nums, i + 1, ans, maxi);           // exclude
    }

    int rob(vector<int>& nums) {
        int maxi = INT_MIN;
        solve(nums, 0, 0, maxi);
        return maxi;
    }
};
