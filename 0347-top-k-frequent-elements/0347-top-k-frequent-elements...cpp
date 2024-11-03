class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //create a map for num and its frequency
        unordered_map<int,int> freqmap; //key: num, value: freq
        for(auto num : nums){
            freqmap[num]++;
        }

        //pair shows freq, num
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        //iterate over map and maintain heap of size k
        for(auto entry : freqmap){
            minHeap.push({entry.second, entry.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int> ans;
        while(!minHeap.empty()){
            auto top = minHeap.top();
            minHeap.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};