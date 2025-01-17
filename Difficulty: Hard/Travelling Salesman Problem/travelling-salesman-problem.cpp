//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Complexity Analysis:
// TC-O(n^2 . 2^n)
// SC-O(n . 2^n)

#include <iostream>
#include <vector>
#include <cmath> // For pow()
#include <climits> // For INT_MAX

using namespace std;
class Solution {
  public:

// Function to find the minimum travel cost using memoization and bitmasking
int findMinCost(int visitedMask, int currentCity, int totalCities, 
                vector<vector<int>> &costMatrix, vector<vector<int>> &dp) {
    
    // Base Case: If all cities have been visited, return the cost to return to city 0 (starting city)
    if (visitedMask == (1 << totalCities) - 1) {
        return costMatrix[currentCity][0]; // Return to the starting city
    }

    // If we have already computed the result for this state, return it
    if (dp[currentCity][visitedMask] != -1) {
        return dp[currentCity][visitedMask];
    }

    int minCost = INT_MAX;

    // Try visiting all unvisited cities
    for (int nextCity = 0; nextCity < totalCities; nextCity++) {
        if ((visitedMask & (1 << nextCity)) == 0) { // Check if the city is unvisited
            int newCost = costMatrix[currentCity][nextCity] + 
                          findMinCost(visitedMask | (1 << nextCity), nextCity, totalCities, costMatrix, dp);
            minCost = min(minCost, newCost);
        }
    }

    // Store the computed result and return it
    return dp[currentCity][visitedMask] = minCost;
}

// Main function to start the TSP algorithm
int tsp(vector<vector<int>> &costMatrix) {
    int totalCities = costMatrix.size();

    // Memoization table initialized with -1
    vector<vector<int>> dp(totalCities, vector<int>(1 << totalCities, -1));

    // Start from city 0 with only city 0 visited (mask = 1)
    return findMinCost(1, 0, totalCities, costMatrix, dp);
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        Solution obj;
        int ans = obj.tsp(cost);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
