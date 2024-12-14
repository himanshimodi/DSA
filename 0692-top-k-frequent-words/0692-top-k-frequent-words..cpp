class Solution {
public:
    struct Compare {
        bool operator() (pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first)
                return a.second < b.second;
            else
                return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;//fre,word
        vector<string>ans;
        int n = words.size();
        
        //put all word in map with its frequency
        for(string word : words){
            mp[word]++;
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare>minHeap;
        for(auto &freq : mp){
            minHeap.push({freq.second,freq.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        while(!minHeap.empty()){
            auto temp= minHeap.top().second;
            minHeap.pop();
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};