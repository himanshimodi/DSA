//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        
        //put k elements of queue into stack
        stack<int>s;
        int count=0;
        int n=q.size();
        
        if(k<=0 || k>n){
            return q;
        }
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            s.push(temp);
            count ++;
            
            if(count == k) break;
        }
        
        //put from stack into queue
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            q.push(temp);
        }
        
        //push n-k elements of queue from its front to its back
        count =0;
        while(!q.empty() && n-k!=0){
            int temp = q.front();
            q.pop();
            q.push(temp);
            count++;
            
            if(count == n-k ) break;
        }
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends