class Solution {
public:
    //Refer to question 1143 - LONGEST COMMON SUBSEQUENCE
    //this is the most optimized way 
    //here we are making a reverse string from the given string and then finding out the longest common subsequence of both the strings
    int solveUsingTabSO(string a, string b){

        vector<int>curr(a.length()+1, 0);
        vector<int>next(a.length()+1, 0);

        for(int j_index = b.length()-1; j_index>=0; j_index--){
            for(int i_index = a.length()-1; i_index>=0; i_index--){
                int ans =0;
                if(a[i_index] == b[j_index]){
                    ans = 1+ next[i_index+1];
                }
                else{
                    ans = 0+ max(next[i_index], curr[i_index+1]);
                }
                curr[i_index] = ans;
            }
            //updating
            next = curr;

        }
        return curr[0];
    }

    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end());
        int ans = solveUsingTabSO(a,s);
        return ans;
    }

    //this is the solution of the longest commong subsequence (leetcode ques- 1143)
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

    int solveUsingTab(string a, string b){
        vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int i_index = a.length()-1; i_index>=0; i_index--){
            for(int j_index = b.length()-1; j_index>=0; j_index--){
                int ans =0;
                if(a[i_index] == b[j_index]){
                    ans = 1+ dp[i_index+1][j_index+1];
                }
                else{
                    ans = 0+ max(dp[i_index][j_index+1], dp[i_index+1][j_index]);
                }
                dp[i_index][j_index] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingTabSO(string a, string b){

        vector<int>curr(a.length()+1, 0);
        vector<int>next(a.length()+1, 0);

        for(int j_index = b.length()-1; j_index>=0; j_index--){
            for(int i_index = a.length()-1; i_index>=0; i_index--){
                int ans =0;
                if(a[i_index] == b[j_index]){
                    ans = 1+ next[i_index+1];
                }
                else{
                    ans = 0+ max(next[i_index], curr[i_index+1]);
                }
                curr[i_index] = ans;
            }
            //updating
            next = curr;

        }
        return curr[0];
    }
};