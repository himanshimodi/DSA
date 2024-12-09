class Solution {
public:

    vector<string> solveRE(string &s,unordered_map<string,bool>&wordMap, int i){
        //BC
        if(i==s.size()){
            return {""};
        }

        vector<string>ans;
        //ek case solve krdo
        for(int j=i; j<s.size();j++){
            string temp = s.substr(i,j-i+1);
            if(wordMap[temp]==true){
                //word found in the map
                auto subAns = solveRE(s,wordMap,j+1);
                for(string sentence : subAns){
                    if(sentence.empty()){
                        ans.push_back(temp);
                    }
                    else{
                        ans.push_back(temp + " " + sentence);
                    }
                }
            }
        }
        return ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>wordMap;
        for(auto word : wordDict){
            wordMap[word] = true;
        }
        
        return solveRE(s,wordMap,0);
    }
};