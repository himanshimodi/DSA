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



        // //max-heap
        // priority_queue<int>pq;
        // for(int i=0; i<nums.size();i++){
        //     int val = nums[i];
        //     pq.push(val);
        // }
        // int ans = -1;
        // while(k--){
        //     ans = pq.top();
        //     pq.pop();
        // }
        // return ans;
    }
};