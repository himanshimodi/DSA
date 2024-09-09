//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    const int MOD = 1e9 + 7; // Modulo value
    
   long long solveUsingMem(int n, int k, vector<long long> &dp){
        // Base cases
        if(n == 1) {
            return k;
        }
        if(n == 2) {
            return (k + (long long)k * (k - 1)) % MOD;
        }
        
        // Check if already solved
        if(dp[n] != -1){
            return dp[n];
        }
        
        // Recurrence relation: (solve(n-1) + solve(n-2)) * (k-1)
        dp[n] = ((solveUsingMem(n - 1, k, dp) + solveUsingMem(n - 2, k, dp)) % MOD * (k - 1)) % MOD;
        return dp[n];
    }
    
    long long solveUsingTabulation(int n, int k){
        //step1 - create a dp
        vector<long long> dp(n+1, -1);
        
        //step 2- analyse base cases
        dp[1] = k;
        dp[2] = (k + (long long)k * (k-1)) % MOD;
        
        //step 3
        for(int i=3; i<=n; i++){
            // step 4 - RE logic
             dp[i] = ( (dp[i-1] + dp[i-2]) % MOD * (k-1) ) % MOD;
        }
        
        //step5 - return
        return dp[n];
    }

     long long spaceOptimised(int n, int k){
        int prev1=k;
        int prev2=k+k*(k-1);
        if(n==1){
            return prev2;
        }
        if(n==2){
            return prev1;
        }
        int curr;
        for(int i=3; i<=n; i++){
            curr = (prev1 + prev2)*(k-1);
            
            //update
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    
    long long countWays(int n, int k) {
        // Step 1: Create a dp array
        // vector<long long> dp(n + 1, -1);
        
        // Step 2: Call the solve function
        // return solveUsingMem(n, k, dp);
        
        int ans = solveUsingTabulation(n,k);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends
