//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int>& q) {
    vector<int> result;
    deque<int> dq;
    int n = q.size();
    int half = n / 2;
    
    // Transfer elements from the queue to a vector
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = q.front();
        q.pop();
    }
    
    // Process and interleave the first and second halves
    for (int i = 0; i < half; ++i) {
        dq.push_back(arr[i]);
    }
    
    for (int i = half; i < n; ++i) {
        dq.push_back(arr[i]);
    }
    
    // Interleave elements from the two halves
    for (int i = 0; i < half; ++i) {
        result.push_back(dq[i]);
        result.push_back(dq[i + half]);
    }

    return result;
}

};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends