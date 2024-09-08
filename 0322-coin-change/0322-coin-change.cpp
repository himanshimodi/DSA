class Solution {
public:
    // this goves TLE
    // int solveUsingRe(vector<int>& coins, int amount) {
    //     // base case
    //     if (amount == 0) {
    //         return 0;
    //     }

    //     // RE
    //     int mini = INT_MAX;
    //     for (int i = 0; i < coins.size(); i++) {
    //         if (amount - coins[i] >= 0) {
    //             int ans = solveUsingRe(coins, amount - coins[i]);
    //             // matlab valid ans hai
    //             if (ans != INT_MAX) {
    //                 int finalAns = 1 + ans;
    //                 mini = min(mini, finalAns);
    //             }
    //         }
    //     }
    //     return mini;
    // }

    // int solveUsingMemo(vector<int>& coins, int amount, vector<int> &dp){
    //     //base case
    //     if (amount == 0) {
    //         return 0;
    //     }

    //     //step 3: if already stored
    //     if(dp[amount]!= -1){
    //         return dp[amount];
    //     }

    //     // step 4: RE logic
    //     int mini = INT_MAX;
    //     for (int i = 0; i < coins.size(); i++) {
    //         if (amount - coins[i] >= 0) {
    //             int ans = solveUsingMemo(coins, amount - coins[i], dp);
    //             // matlab valid ans hai
    //             if (ans != INT_MAX) {
    //                 int finalAns = 1 + ans;
    //                 mini = min(mini, finalAns);
    //             }
    //         }
    //     }
    //     //step 2
    //     dp[amount] = mini;
    //     return dp[amount];
    // }

    int solvedUsingTabulation(vector<int>& coins, int amount){
        //step 1: create a dp
        int n = amount;
        vector<int> dp (n+1, INT_MAX);

        //step2 - base case analyse
        dp[0] = 0;

        for(int val=1; val<=amount; val++){
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
            if (val - coins[i] >= 0) {
                int ans = dp[val - coins[i]];
                // matlab valid ans hai
                if (ans != INT_MAX) {
                    int finalAns = 1 + ans;
                    mini = min(mini, finalAns);
                }
            }
        }
        //step 2
        dp[val] = mini;
        }
        return dp[amount]; 
    }

    int coinChange(vector<int>& coins, int amount) {
        // int ansHere = solveUsingRe(coins, amount);
        // if(ansHere == INT_MAX){
        //     return -1;
        // }
        // else{
        //     return ansHere;
        // }

        //step 1: create a dp
        // int n = amount;
        // vector<int> dp (n+1, -1);

        int ansHere = solvedUsingTabulation(coins, amount);
        if(ansHere == INT_MAX){
            return -1;
        }
        else{
            return ansHere;
        }
    }
};