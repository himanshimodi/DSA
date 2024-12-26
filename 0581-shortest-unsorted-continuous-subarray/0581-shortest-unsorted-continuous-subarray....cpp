class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // Monotonic stack for finding boundaries
        stack<int> st;
        int left = n, right = 0;

        //find left boundry
        for(int i=0;i<n;i++){
            int curr = nums[i];
            while(!st.empty() && nums[st.top()]>curr){
                left = min(left,st.top());
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        //find right boundry
        for(int i=n-1;i>=0;i--){
            int curr = nums[i];
            while(!st.empty() && nums[st.top()]<curr){
                right = max(right,st.top());
                st.pop();
            }
            st.push(i);
        }

        if(right<=left){
            return 0;
        }

        return right-left+1;
    }
};