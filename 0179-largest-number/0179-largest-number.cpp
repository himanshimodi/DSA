class Solution {
public:
    //custom comparator function
    static bool mycomp(string a,string b){
        string t1 = a+b;
        string t2 = b+a;

        return t1 > t2; //returns whatever combo of a,b ( t1 or t2) is big
    }
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(auto n : nums){
            snums.push_back(to_string(n));
        }
        sort(snums.begin(), snums.end(), mycomp);

        // corner case: if first charcter is zero.
        if(snums[0] == "0") return "0";

        string ans="";
        for(auto str : snums){
            ans = ans + str;
        }
        return ans;
    }
};
//commenting