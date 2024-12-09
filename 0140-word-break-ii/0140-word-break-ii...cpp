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

    vector<string> solveMem(string &s,unordered_map<string,bool>&wordMap, int i,unordered_map<int,vector<string>>&dp){
        //BC
        if(i==s.size()){
            return {""};
        }

        vector<string>ans;

        //step 3 - if dp already exists
        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        //ek case solve krdo
        for(int j=i; j<s.size();j++){
            string temp = s.substr(i,j-i+1);
            if(wordMap[temp]==true){
                //word found in the map
                auto subAns = solveMem(s,wordMap,j+1,dp);
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
        dp[i] = ans;
        return dp[i];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>wordMap;
        for(auto word : wordDict){
            wordMap[word] = true;
        }
        
        // return solveRE(s,wordMap,0);

        unordered_map<int,vector<string>>dp;
        return solveMem(s,wordMap,0,dp);
    }
};