class Solution {
public:
    // NOT THE IDLE SOLUTION DONT REVISE FROM THIS
    //NEXT COMMIT WILL HAVE THE PROPER REVISE-ABLE SOLUTION
void help(int i, string &s,string &temp, vector<string> &ans, unordered_map<char,string> &m){
    //base case
    if(s.empty()) return;
    if(i==s.size()){
        ans.push_back(temp);
        return;
    }

    string str=m[s[i]];
    for(int j=0; j<str.size();j++){
        temp.push_back(str[j]);
        help(i+1, s, temp, ans, m);//recursion
        temp.pop_back();//backtrack
    }
}

vector<string> letterCombinations(string s) {
        unordered_map<char, string> m;
        vector<string> ans;
        string temp;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        help(0,s,temp,ans,m);
        return ans;
    }
};