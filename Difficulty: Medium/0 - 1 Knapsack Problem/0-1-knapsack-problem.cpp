//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solveUsingRecursion(int capacity, vector<int>& wt, vector<int>& profit, int index, int n) {
    // Base case: if no items are left or the capacity is 0
    if (index >= n) {
        return 0;
    }

    // Include the item if its weight is less than or equal to capacity
    int include = 0;
    if (wt[index] <= capacity) {
        include = profit[index] + solveUsingRecursion(capacity - wt[index], wt, profit, index + 1, n);
    }

    // Exclude the item
    int exclude = solveUsingRecursion(capacity, wt, profit, index + 1, n);

    // Return the maximum of including or excluding the item
    return max(include, exclude);
}

// Function to return max value that can be put in knapsack of capacity W
int knapSack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();  // Number of items
    return solveUsingRecursion(W, wt, val, 0, n);
}

    
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends