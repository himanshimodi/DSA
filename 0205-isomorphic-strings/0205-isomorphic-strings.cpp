class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256]={0};//hash array initialised with zero
        int isTCharMapped[256]= {0}; //boolean hashmap initialised with zero

        for(int i=0; i<s.size();i++){
            //if s is not mapped
            if((hash[s[i]] == 0)&&(isTCharMapped[t[i]] == 0)){ 
                hash[s[i]] = t[i];
                isTCharMapped[t[i]] = 1;
            }
        }

        for(int i=0; i<t.size();i++){ //size of s and t is the same
            //if s is already mapped to another letter
            if(char (hash[s[i]]) != t[i]){
                return false;
            }
        }
        return true;
    }
};