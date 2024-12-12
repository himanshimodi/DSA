class Solution {
public:
    void solve(int n,int k,int start,vector<vector<int>>&ans,vector<int>&combo){
        //BC
        if(k == 0){
            ans.push_back(combo);
            return;
        }
        for(int i=start;i<=n;i++){
            combo.push_back(i);
            solve(n,k-1,i+1,ans,combo);
            combo.pop_back();   
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>combo;
        vector<vector<int>>ans;
        int start=1;
        solve(n,k,start,ans,combo);
        return ans;
    }
};