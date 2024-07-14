//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void solve(stack<int> &st,int x){
        
        //base case
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int topElement = st.top();
        
        st.pop();
        
        //rec cal
        solve(st, x);
        
        //backtrack
        st.push(topElement);
    }
    stack<int> insertAtBottom(stack<int> &st,int x){
        
        //stack is empty, cannot insert at bottom 
        if(st.empty()){
            return st;
        }
        
        int topElement = st.top();
        st.pop();
        solve(st, x);
        st.push(topElement);
        return st;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends