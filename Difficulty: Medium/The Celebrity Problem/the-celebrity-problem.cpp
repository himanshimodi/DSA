//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        //step1: push all elements [people] in the stack
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        //step2: run discard method and find out someone who might be a celeb
        while(st.size()!=1){
            int a= st.top(); st.pop();
            int b= st.top(); st.pop();
            
            //if a knows b
            if(M[a][b] == true){
                //then a is not a celeb so discard a and push b
                st.push(b);
            }
            else{//if b knows a 
                //then b is not a celeb so discard b and push a
                st.push(a);
            }
        }
        
        //now the size of the stack is 1
        //check if it a actually a celeb or not
        int mightBeACeleb = st.top(); st.pop();
        
        //celeb should not know anyone
        for(int i=0; i<n; i++){
            // if(M[mightBeACeleb][i] == 0){
            //     return mightBeACeleb;
            // }
            if(M[mightBeACeleb][i] != 0){
                return -1;
            }
        }
        
        //everyone should know the celeb
        for(int i=0; i<n; i++){
            // if(M[i][mightBeACeleb] == 1 && i!= mightBeACeleb){
            //     return mightBeACeleb;
            // }
            if(M[i][mightBeACeleb] != 1 && i!= mightBeACeleb){
                return -1;
            }
        }
        return mightBeACeleb;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
