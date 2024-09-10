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

int solveUsingMem(int capacity, vector<int>& wt, vector<int>& profit, int index, int n, vector<vector<int>>& dp) {
    // Base case: if no items are left or the capacity is 0
    if (index >= n) {
        return 0;
    }

    // Check if result already exists
    if (dp[capacity][index] != -1) {
        return dp[capacity][index];
    }

    // Include the item if its weight is less than or equal to capacity
    int include = 0;
    if (wt[index] <= capacity) {
        include = profit[index] + solveUsingMem(capacity - wt[index], wt, profit, index + 1, n, dp);
    }

    // Exclude the item
    int exclude = solveUsingMem(capacity, wt, profit, index + 1, n, dp);

    // Memoize and return the maximum of including or excluding the item
    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

int solveUsingTabulation(int capacity, vector<int>& wt, vector<int>& profit, int n) {
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

    // Base case: no items left, profit is 0
    for (int row = 0; row <= capacity; row++) {
        dp[row][n] = 0;
    }

    // Tabulation process (bottom-up)
    for (int i = 0; i <= capacity; i++) {
        for (int j = n - 1; j >= 0; j--) {
            int include = 0;
            if (wt[j] <= i) {
                include = profit[j] + dp[i - wt[j]][j + 1];
            }
            int exclude = 0 + dp[i][j + 1];
            dp[i][j] = max(include, exclude);
        }
    }

    return dp[capacity][0];
}

int solveUsingTabulationSO(int capacity, vector<int>& wt, vector<int>& profit, int n) {
    vector<int> next(capacity + 1, 0);
    vector<int> curr(capacity + 1, -1);

    // Tabulation with space optimization
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i <= capacity; i++) {
            int include = 0;
            if (wt[j] <= i) {
                include = profit[j] + next[i - wt[j]];
            }
            int exclude = 0 + next[i];
            curr[i] = max(include, exclude);
        }
        // Shifting the current row to the next row
        next = curr;
    }
    return curr[capacity];
}

int solveUsingTabulationSO2(int capacity, vector<int>& wt, vector<int>& profit, int n) {
    vector<int> next(capacity + 1, 0);

    // Tabulation with space optimization (alternative)
    for (int j = n - 1; j >= 0; j--) {
        for (int i = capacity; i >= 0; i--) {
            int include = 0;
            if (wt[j] <= i) {
                include = profit[j] + next[i - wt[j]];
            }
            int exclude = 0 + next[i];
            next[i] = max(include, exclude);
        }
    }
    return next[capacity];
}

// Function to return max value that can be put in knapsack of capacity W
int knapSack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();  // Number of items

    // Uncomment the method you'd like to use:

    // Recursive approach:
    // return solveUsingRecursion(W, wt, val, 0, n);

    // Memoization approach:
    // vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
    // return solveUsingMem(W, wt, val, 0, n, dp);

    // Tabulation approach:
    // return solveUsingTabulation(W, wt, val, n);

    // Space Optimized Tabulation approach:
    // return solveUsingTabulationSO(W, wt, val, n);

    // Alternative Space Optimized Tabulation approach:
    return solveUsingTabulationSO2(W, wt, val, n);
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
