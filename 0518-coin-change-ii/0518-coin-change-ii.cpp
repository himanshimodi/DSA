class Solution {
public:
    int solve(int amount, vector<int>& coins, int i){
        //BC
        if(i>=coins.size() || amount < 0){
            return 0;
        }
        if(amount==0){
            return 1;
        }

        //ek case
        //include
        int ans=0;
        ans+= solve(amount-coins[i],coins,i);

        //exclude
        ans+=solve(amount,coins,i+1);

        return ans;
    }

    int memo(int amount, vector<int>& coins, int i,vector<vector<long long>>&dp){
        //BC
        if(i>=coins.size() || amount < 0){
            return 0;
        }
        if(amount==0){
            return 1;
        }

        //step 3: check if dp is already initialised
        if(dp[amount][i]!=-1){
            return dp[amount][i];
        }

        //step 2 : store and return in dp
        //ek case
        //include
        long long ans=0;
        ans+= memo(amount-coins[i],coins,i,dp);

        //exclude
        ans+=memo(amount,coins,i+1,dp);
        dp[amount][i] = ans;
        return dp[amount][i];
    }

    int tabulation(int amount, vector<int>& coins){
        int n = coins.size();
        //step 1
        vector<vector<long long>>dp(amount+1,vector<long long>(n+1,0));
        // step 2: BC analyze
        for(int i=0;i<=n;i++){
            dp[0][i] = 1;
        }
        for(int amt=1;amt<=amount;amt++){
            for(int i = n-1;i>=0;i--){
                //include
                long long include=0;
                if(amt-coins[i]>=0){
                    include+= dp[amt-coins[i]][i];
                }
                long long exclude =0;
                //exclude
                exclude+=dp[amt][i+1];
                dp[amt][i] = include+ exclude;
            }
        }        
        return dp[amount][0];
    }

    int change(int amount, vector<int>& coins) {
        // return solve(amount,coins,0); 
        // int n = coins.size();

        // //step 1 
        // vector<vector<long long>>dp(amount+1,vector<long long>(n+1,-1));
        // return memo(amount,coins,0,dp);

        return tabulation(amount,coins);
    }
};