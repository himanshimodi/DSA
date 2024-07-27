class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int> ans;

        //first window of k size
        for(int i=0; i<k; i++){
            //remove small elements
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            //inserting index so that we can check,
            // out of window ka element(basically next element)
            dq.push_back(i);
        }
        
        //store first window ka ans
        ans.push_back(nums[dq.front()]);

        //remaining windows ko process krna
        for(int i=k; i<nums.size(); i++){
            //remove out of window ke elements
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            //inserting index so that we can check,
            // out of window ka element(basically next element)
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};