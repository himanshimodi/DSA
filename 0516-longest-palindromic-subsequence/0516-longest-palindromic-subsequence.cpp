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
};