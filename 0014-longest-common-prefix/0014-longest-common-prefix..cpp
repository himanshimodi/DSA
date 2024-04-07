class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i=0;
        while(true){
            char curr_ch=0;
            for(auto s: strs){
                if(i>=s.size()){  // out of bound
                    curr_ch=0;
                    break;
                }
                if(curr_ch == 0){
                    curr_ch = s[i];
                }
                else if( curr_ch != s[i]){
                    curr_ch=0;
                    break;
                }
            }
            if(curr_ch == 0){
                break;
            }
            ans.push_back(curr_ch);
            i++;
        }
        return ans;
    }
};