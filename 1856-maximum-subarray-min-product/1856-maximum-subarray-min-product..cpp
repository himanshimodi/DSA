class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const long long mod = 1e9+7;
        int n = nums.size();
        long long ans=0;

        //find prefix sum
        vector<long long>prefixSum(n+1,0);
        for(int i=0;i<n;i++){
            prefixSum[i+1] = prefixSum[i]+nums[i];
        }

        //calc prevSmaller and nextSmaller
        vector<int>prevSmaller(n,-1);
        vector<int>nextSmaller(n,n);
        stack<int>st;

        //prevSmaller
        for(int i=0;i<n;i++){
            long long curr=nums[i];
            while(!st.empty() && nums[st.top()]>=curr){
                st.pop();
            }
            if(!st.empty()){
                prevSmaller[i] = st.top();
            }
            st.push(i); //only playing with index
        }
        
        //clear the stack
        while(!st.empty()){
            st.pop();
        }

        //nextSmaller
        for(int i=n-1;i>=0;i--){
            long long curr=nums[i];
            while(!st.empty() && nums[st.top()]>=curr){
                st.pop();
            }
            if(!st.empty()){
                nextSmaller[i] = st.top();
            }
            st.push(i); //only playing with index
        }

        //calc max-min product
        for(int i=0;i<n;i++){
            long long totalSum = prefixSum[nextSmaller[i]] - prefixSum[prevSmaller[i]+1];
            long long minProduct = nums[i]*totalSum;
            ans = max(ans,minProduct);
        }

        return ans%mod;
    }
};