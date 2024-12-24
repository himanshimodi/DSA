class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //UNLIKE THE USUAL nextGreaterEle WE ARE NOT PLAYING WITH INDEXES HERE, INSTEAD WE ARE PLAYING WITH THE ACTUAL VALUE
        vector<int>ans(nums.size(),0);
        stack<int>st;
        st.push(-1);
        int n = nums.size();

        for(int i = n-1 ; i>=0 ; i--){
          st.push(nums[i]);
        }

        for(int i=n-1;i>=0;i--){
            int curr = nums[i];
            while(st.top()!=-1 && st.top()<=curr){
                st.pop();
            }
            if(st.empty()){
                st.push(nums[i]);
                ans[i] = -1;
            }
            else{
                ans[i]= st.top();
            }
            st.push(nums[i]);
        }

        // int lastEle = nums[n-1];
        // for(int i=0;i<n;i++){
        //     if(lastEle<nums[i]){
        //         ans[n-1] = nums[i];
        //     }
        // }

        return ans;
    }
};