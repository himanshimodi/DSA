class Solution {
public:
    bool isPalindrome(string &str){
        int i=0;
        int j=str.size()-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    void solveRE(int i, vector<string> &ans, vector<vector<string>> &finalans, string &s){
        //BC
        if(i>=s.size()){
            finalans.push_back(ans);
            return;
        }

        //ek case
        for(int j=i;j<s.size();j++){
            string substring = s.substr(i,j-i+1);
            if(isPalindrome(substring)){
                ans.push_back(substring);
                solveRE(j+1,ans,finalans,s);
                ans.pop_back(); //Backtrack
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> finalans;
        vector<string> ans;
        solveRE(0, ans, finalans, s);
        return finalans;
    }
};