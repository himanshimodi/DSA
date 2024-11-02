class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //create min heap 
        priority_queue<int, vector<int>, greater<int>>pq;

        //initialise i.e, insert first k elements
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }

        //process the remaining elements 
        for(int i=k; i<nums.size(); i++){
            int ele = nums[i];
            if(ele > pq.top()){
                pq.pop();
                pq.push(ele);
            }
        }
        int ans = pq.top();
        return ans;
    }
};