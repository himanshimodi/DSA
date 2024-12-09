class Solution {
public:

    bool solveRE(string &s, set<string>& wordSet, int i){

        int n = s.size();
        string temp="";
        //BC
        if(i == n) return true;

        //ek case
        for(int j=i; j<n;j++){
            temp += s[j];
            //if temp exists in the set
            bool found = wordSet.find(temp)!=wordSet.end();
            if( found == true){
                //agar word mila
                if(solveRE(s,wordSet,j+1)){
                    return true;
                }
            }
        }
        return false;
    }

    bool solveMem(string &s, set<string>& wordSet, int i,vector<int> &dp){

        int n = s.size();
        string temp="";
        //BC
        if(i == n) return dp[i];

        //step 3
        if(dp[i]!=-1){
            return dp[i];
        }

        //ek case
        for(int j=i; j<n;j++){
            temp += s[j];
            //if temp exists in the set
            bool found = wordSet.find(temp)!=wordSet.end();
            if( found == true){
                //agar word mila
                if(solveMem(s,wordSet,j+1,dp)){
                    dp[j] = true;
                    return dp[j];
                }
            }
        }
        dp[i] = false;
        return dp[i];
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        set<string> wordSet(wordDict.begin(),wordDict.end());

        // int ans = solveRE(s, wordSet,0);
        // return ans;

        vector<int> dp(n+1,-1);
        int ans = solveMem(s, wordSet,0,dp);
        return ans;
    }
};