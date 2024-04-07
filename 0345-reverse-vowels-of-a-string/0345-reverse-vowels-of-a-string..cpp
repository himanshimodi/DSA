class Solution {
public:
    bool isVowel(char ch){

        // if the character is a vowel return true else return false
        if( ch=='a'|| ch=='e'|| ch=='i'||ch=='o'||ch=='u' || ch=='A'|| ch=='E'||   ch=='I'||ch=='O'||ch=='U'){
            return true;
        }
        else{
            return false;
        }
    }

    string reverseVowels(string s) {

        // using 2 pointer approach
        int i=0;
        int n=s.size();
        int j= n-1;

        while(i<j){
            // if both characters are vowels
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i] , s[j]);
                i++;
                j--;
            }
            // if ith character is not a vowel
            else if(!isVowel(s[i])){
                i++;
            }
            // if jth character is not a vowel
            else{
                j--;
            }
        }
        return s;
    }
};