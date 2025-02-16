class Solution {
public:
    unordered_map<string,int> map;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;

        for(int i=0;i<words.size();i++){
            map[words[i]]++;
        }
        int wordlen = words[0].size();

        for(int offset=0;offset<wordlen;offset++){
            unordered_map<string,int> vis;
            int count =0;
            for(int i=offset;i+wordlen<=s.length();i=i+wordlen){
                string substr = s.substr(i,wordlen);
                if(map.find(substr) == map.end()){
                    vis.clear();
                    count =0;
                }
                else{
                    vis[substr]++;
                    count++;
                    while(vis[substr]>map[substr]){
                        //toh removal krdo
                        string temp = s.substr(i-(count-1)* wordlen,wordlen);
                        vis[temp]--;
                        count--;
                    }
                    if(count == words.size()){
                        ans.push_back(i-(count-1)*wordlen);
                    }
                }
            }
        }
        return ans;
    }
};