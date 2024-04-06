class Solution {
public:
    bool isAnagram(string s, string t){
        int map[256]={0};

        //iterating through s and counting the number of characters
        for(int i=0; i<s.size(); i++){
            map[s[i]]++;
        }

        //iterating through t and decreasing the counts of the characters
        for(int i=0; i<t.size(); i++){
            map[t[i]]--;
        }

        //if map becomes zero as initial value then it is an anagram otherwise not 
        for(int i=0; i<256; i++){
            if(map[i]!=0){
                return false;
            }
        }
        return true;
    }













    // bool isAnagram(string s, string t) {
    //     if(s.length()!=t.length()){
    //         return false;
    //     }

    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());

    //     if(s==t){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }

    // }
};