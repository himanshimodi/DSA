class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int>ans;

        //process first window
        for(int i=0; i<k; i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            //include curr ele
            dq.push_back(i); //index he dal rhe hai queue mai
        }
            //store ans
            ans.push_back(nums[dq.front()]);

            //remaining window ko process
            for(int i=k; i<nums.size();i++){
                //removal
                if(!dq.empty() && i - dq.front() >= k){
                    dq.pop_front();
                }

                //addtion
                while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
                }
                //include curr ele
                dq.push_back(i);

                //store ans
                ans.push_back(nums[dq.front()]);
            }
        return ans;
    }
};