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
    
    long long countWays(int n, int k) {
        // Step 1: Create a dp array
        vector<long long> dp(n + 1, -1);
        
        // Step 2: Call the solve function
        return solveUsingMem(n, k, dp);
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