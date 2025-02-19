class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string>ans;

        if(s.length()<10){
            return {};
        }
        for(int i=0;i<= s.length()-10;i++){
            string currwindow = s.substr(i,10);
            mp[currwindow]++;
        }

        for(auto &i: mp){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};