//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    bool isPossible(vector<int> stalls, int k, int ans){
        //can we place k cows with atleast 'mid' distance betw them
        int pos=stalls[0];
        int c=1;
        
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i] - pos >= ans){
                c++; // updating count to the next cow
                pos=stalls[i]; //updating positions of the next cow
            }
            if(c==k){ // if count = actual no. of given cows
                return true;
            }
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls){
        sort(stalls.begin(), stalls.end());
        int s=0;
        int e=stalls[stalls.size()-1]- stalls[0];
        int ans=0;
        int mid=s+(e-s)/2;
        
        while(s<=e){
            if(isPossible(stalls, k, mid)){
                ans=mid; // can be a possible ans
                s=mid + 1; // updating our search space
            }
            else{
                e=mid - 1; // limiting our search space
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends