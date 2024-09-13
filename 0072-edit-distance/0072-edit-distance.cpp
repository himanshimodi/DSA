class Solution {
public:

    int solveUsingRe(string &a, string &b, int i, int j){
        //base case
        if(j == b.length()){
            //number of deletions
            return a.length() - i;
        }
        if(i == a.length()){
            return b.length() - j;
        }

        int ans = 0;
        //matching characters
        if(a[i] == b[j]){
            ans = 0 + solveUsingRe(a,b,i+1,j+1);
        }
        //not matching characters
        else{
            int replace = 1 + solveUsingRe(a,b,i+1,j+1);
            int insert = 1 + solveUsingRe(a,b,i,j+1);
            int remove = 1 + solveUsingRe(a,b,i+1,j);
            ans = min(insert,min(remove,replace));
        }
        return ans;
    }

    int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>>&dp){
        //base case
        if(j == b.length()){
            //number of deletions
            return a.length() - i;
        }
        if(i == a.length()){
            return b.length() - j;
        }

        //check if ans already exists
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        //matching characters
        if(a[i] == b[j]){
            ans = 0 + solveUsingMem(a,b,i+1,j+1,dp);
        }
        //not matching characters
        else{
            int replace = 1 + solveUsingMem(a,b,i+1,j+1,dp);
            int insert = 1 + solveUsingMem(a,b,i,j+1,dp);
            int remove = 1 + solveUsingMem(a,b,i+1,j,dp);
            ans = min(insert,min(remove,replace));
        }
        //store ans
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveUsingTab(string &a, string &b ){

        //step 1 : create a dp array
        vector<vector<int>> dp (a.length()+1,vector<int>(b.length()+1, -1));

        //analyse base cases
        for(int col=0; col<=b.length(); col++){
            dp[a.length()][col] = b.length()-col;
        }
        for(int row=0; row<=a.length(); row++){
            dp[row][b.length()] = a.length()-row;
        }

        //Re logic
        for(int i=a.length()-1; i>=0; i--){
            for(int j=b.length()-1;j>=0; j--){
                int ans = 0;
                //matching characters
                if(a[i] == b[j]){
                ans = 0 + dp[i+1][j+1];
                }
                //not matching characters
                else{
                int replace = 1 + dp[i+1][j+1];
                int insert = 1 + dp[i][j+1];
                int remove = 1 + dp[i+1][j];
                ans = min(insert,min(remove,replace));
                }
                //store ans
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingTabSO(string &a, string &b ){

        //step 1
        vector<int> curr(a.length()+1, -1);
        vector<int> next(a.length()+1, -1); // a is number of rows

        //analyse base cases
        // for(int col=0; col<=b.length(); col++){
        //     dp[a.length()][col] = b.length()-col;
        // }

        //initialise krre hai for pattern matching
        for(int row=0; row<=a.length(); row++){
            next[row] = a.length()-row;
        }

        //Re logic
        for(int j=b.length()-1;j>=0; j--){
            //har new column ke last dabbe mai ans insert karo
            //MOST IMP LINE
            curr[a.length()] = b.length()-j;
            for(int i=a.length()-1; i>=0; i--){
                int ans = 0;
                //matching characters
                if(a[i] == b[j]){
                ans = 0 + next[i+1];
                }
                //not matching characters
                else{
                int replace = 1 + next[i+1];
                int insert = 1 + next[i];
                int remove = 1 + curr[i+1];
                ans = min(insert,min(remove,replace));
                }
                //store ans
                curr[i] = ans;
            }
            //updating
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        // int ans = solveUsingRe(word1,word2,i,j);
        // return ans;

        // vector<vector<int>> dp (word1.length()+1,vector<int>(word2.length()+1, -1));
        // int ans = solveUsingMem(word1,word2,i,j,dp);
        // return ans;

        // int ans = solveUsingTab(word1,word2);
        // return ans;

        int ans = solveUsingTabSO(word1,word2);
        return ans;
    }
};