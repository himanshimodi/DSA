//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    //if size of string is odd then it is invalid
    if( s.size() % 2 == 1){
        return -1;
    }
    
    stack<char> st;
    for( auto ch : s){
        if(!st.empty() && ch =='{'){
            st.push(ch);
        }
        else{
            // it is a closing bracket and st.top contains {
            //here we are basically removing valid parentheses
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{// it is an { and st.top() also contains {
                // it is an } and st.top() also contains }
                // it is an { and st.top() contains a }, basically => }{
                st.push(ch);
            }
        }
    }
    int count=0;
    while(!st.empty()){
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        
        //if same characters
        if(a==b){
            count+=1;
        }
        else{//if diff characters
            count+=2;
        }
    }
    return count;
}