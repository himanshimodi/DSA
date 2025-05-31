class Solution {
public:
    bool isPalindrome(string s) {
        string newstring;
        for(char str : s){
            if(isalpha(str) || isdigit(str)){
                newstring+=tolower(str);
            }
            else{
                continue;
            }
        }
        int start = 0;
        int end = newstring.size()-1;
        while(start<=end){
            if(newstring[start]==newstring[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};