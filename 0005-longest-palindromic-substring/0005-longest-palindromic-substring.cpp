class Solution {
public:
    bool checkPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
    string ans="";
    //extract all substrings
    for(int i=0;i<s.size();i++){
        for(int j=i; j<s.size();j++){
            if(checkPalindrome(i,j,s)){
                string t=s.substr( i, j-i+1); //store palindromic substring in t
                ans= t.size()>ans.size() ? t : ans;
            }
        }            
    }
    return ans;
    }
};