class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int thirdEle = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < thirdEle)
                return true;
            while(!st.empty() && nums[i] > st.top()){
                thirdEle = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};