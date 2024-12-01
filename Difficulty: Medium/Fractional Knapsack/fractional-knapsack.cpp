//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Create a max heap with value-to-weight ratio as the key
        priority_queue<pair<double, pair<int, int>>> pq;

        // Push items into the max heap
        for (int i = 0; i < val.size(); i++) {
            double ratio = (double)val[i] / wt[i];
            pq.push({ratio, {val[i], wt[i]}});
        }

        double totalValue = 0.0;

        // Process items in the heap
        while (capacity > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            double ratio = top.first;
            int value = top.second.first;
            int weight = top.second.second;

            if (capacity >= weight) {
                // Include the entire item
                totalValue += value;
                capacity -= weight;
            } else {
                // Include the fractional part of the item
                totalValue += ratio * capacity;
                break; // Knapsack is full
            }
        }

        return totalValue;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends