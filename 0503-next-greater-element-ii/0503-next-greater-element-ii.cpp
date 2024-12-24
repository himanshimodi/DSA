class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        
        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = i % n;
            while (!st.empty() && nums[st.top()] <= nums[curr]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[curr] = nums[st.top()];
            }
            st.push(curr);
        }
        
        return ans;
    }
};
