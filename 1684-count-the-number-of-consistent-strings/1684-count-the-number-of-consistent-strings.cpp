class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int c =0;
        for(int i=0; i<words.size(); i++){
            set<char> st(words[i].begin(), words[i].end());

            bool flag = true;
            for(auto x : st){
                auto it = find(allowed.begin(), allowed.end(), x);
                if(it == allowed.end()){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                c++;
            }
        }
        return c;
    }
};