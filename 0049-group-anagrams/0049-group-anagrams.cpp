class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <string, vector<string>> mp;

        //iterate through the outer bracket
        for(auto str :strs){
            string s=str; //temporary variable which stores the value of str
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto it=mp.begin(); it!=mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};