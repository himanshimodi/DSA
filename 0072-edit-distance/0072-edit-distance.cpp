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

    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        int ans = solveUsingRe(word1,word2,i,j);
        return ans;
    }
};