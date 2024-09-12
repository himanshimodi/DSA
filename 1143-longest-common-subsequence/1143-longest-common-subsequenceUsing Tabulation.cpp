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



    int longestCommonSubsequence(string text1, string text2) {

        int i=0;
        int j=0;
        // int ans = solveUsingRe(text1,text2,i,j);
        // return ans;

        // vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        // int ans = solveUsingMem(text1,text2,i,j, dp);
        // return ans;

        int ans = solveUsingTab(text1,text2);
        return ans;
    }
};