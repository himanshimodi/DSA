class Solution {
public:
    int solveUsingRe(string a, string b, int i, int j){
        //BC
        if(i>=a.length()){
            return 0;
        }
        if(j>=b.length()){
            return 0;
        }

        //ek case solve krdo
        int ans =0;
        if(a[i] == b[j]){
            ans = 1+ solveUsingRe(a,b,i+1,j+1);
        }
        else{
            ans = 0+ max(solveUsingRe(a,b,i,j+1), solveUsingRe(a,b,i+1,j));
        }
        return ans;
    }

    //this is a 2D dp ques
    int solveUsingMem(string &a, string &b, int i, int j,vector<vector<int>>&dp){
        //BC
        if(i>=a.length()){
            return 0;
        }
        if(j>=b.length()){
            return 0;
        }

        //check if it already exists
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //ek case solve krdo
        int ans =0;
        if(a[i] == b[j]){
            ans = 1+ solveUsingMem(a,b,i+1,j+1,dp);
        }
        else{
            ans = 0+ max(solveUsingMem(a,b,i,j+1,dp), solveUsingMem(a,b,i+1,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {

        int i=0;
        int j=0;
        // int ans = solveUsingRe(text1,text2,i,j);
        // return ans;

        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        int ans = solveUsingMem(text1,text2,i,j, dp);
        return ans;
    }
};