class Solution {
public:
    int expandAroundIndex(string s, int i, int j){
        int count=0;

        //jab tak match krta jaye tab tak count++ karo and i-- karo and j++ karo
        while(i>=0 && j<s.length() && s[i] == s[j]){
            count ++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalCount = 0;
        int n = s.length();

        for(int center=0; center<n; center++){
            //for odd indexes
            int oddAns = expandAroundIndex(s,center,center);
            totalCount += oddAns;

            //for even indexes
            int evenAns = expandAroundIndex(s,center,center+1);
            totalCount += evenAns;
        }
        return totalCount;
    }
};