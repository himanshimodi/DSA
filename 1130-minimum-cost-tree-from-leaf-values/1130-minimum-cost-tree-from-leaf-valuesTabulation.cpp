class Solution {
public:

    int solveUsingRe(vector<int>&arr, map<pair<int,int>, int>&maxi, int s, int e){
        //base case
        if(s>=e){
            return 0;
        }

        int ans = INT_MAX;
        //for partitioning
        for(int i=s; i<e; i++){
            ans = min(ans, (maxi[{s,i}]* maxi[{i+1, e}]) 
                            + solveUsingRe(arr,maxi,s,i)
                            + solveUsingRe(arr,maxi,i+1,e));
        }
        return ans;
    }

    int solveUsingMem(vector<int>&arr, map<pair<int,int>, int>&maxi, int s, int e, vector<vector<int>>&dp){
        //base case
        if(s>=e){
            return 0;
        }

        if(dp[s][e]!=-1){
            return dp[s][e];
        }

        int ans = INT_MAX;
        //for partitioning
        for(int i=s; i<e; i++){
            ans = min(ans, (maxi[{s,i}]* maxi[{i+1, e}]) 
                            + solveUsingMem(arr,maxi,s,i,dp)
                            + solveUsingMem(arr,maxi,i+1,e,dp));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    int solveUsingTab(vector<int>& arr,map<pair<int,int>,int>& maxi){
        int n = arr.size();
        vector<vector<int>>dp(n+2, vector<int>(n+1,0));

        for(int s=n; s>=0; s--){
            for(int e=0;e<=n-1; e++){
                if(s>=e){
                    continue;
                }
                int ans = INT_MAX;
                //for partitioning
                for(int i=s; i<e; i++){
                    ans = min(ans, (maxi[{s,i}]* maxi[{i+1, e}]) + dp[s][i] + dp[i+1][e]);
                }
                dp[s][e] = ans;
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        //pre computation
        map<pair<int,int>,int> maxi;
        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        int n= arr.size();
        int start =0;
        int end = n-1;

        // int ans = solveUsingRe(arr,maxi,start,end);
        // return ans;

        // vector<vector<int>>dp(n+2, vector<int>(n+1,-1));
        // int ans = solveUsingMem(arr,maxi,start,end,dp);
        // return ans;

        int ans = solveUsingTab(arr,maxi);
        return ans;
    }
};