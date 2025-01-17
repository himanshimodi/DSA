//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool recursive(vector<int>& arr, vector<vector<int>>& dp, int n, int sum){
        if(sum==0) return true;
        if(n==0) return false;
        if(dp[n][sum]!=-1) return dp[n][sum];
        if(arr[n-1]<=sum){
            return dp[n][sum] = recursive(arr, dp, n-1, sum-arr[n-1]) || recursive(arr, dp, n-1, sum);
        }
        else{
            return dp[n][sum] = recursive(arr, dp, n-1, sum);
        }
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size()+1, vector<int>(target+1, -1));
        return recursive(arr, dp, arr.size(), target);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends