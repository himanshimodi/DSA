class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freqMap;//key-char,val-freq
        priority_queue<pair<int,char>>maxHeap;
        string ans="";

        for(char ch:s){
            freqMap[ch]++;
        }
        //iterate over map and maintain a maxHeap
        for(auto entry : freqMap){
            maxHeap.push({entry.second,entry.first});
        }
        while(!maxHeap.empty()){
            auto top = maxHeap.top();
            maxHeap.pop();

            int myFreq = top.first;
            char myChar = top.second;
            while(myFreq--){
                ans+=myChar;
            }
        }
        return ans;
    }
};