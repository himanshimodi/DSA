class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        vector<int>ans(nums.size(),0);//size = nums.size() and initialised by zero
        //pair-> {value,index}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        for(int i=0;i<nums.size();i++){
            minHeap.push({nums[i],i});
        }
        while(k--){
            auto[val,index] = minHeap.top();
            minHeap.pop();
            minHeap.push({val*multiplier,index});
        }
        while(!minHeap.empty()){
            int val = minHeap.top().first;
            int index = minHeap.top().second;
            minHeap.pop();
            ans[index]=val;
        }
        return ans;
    }
};