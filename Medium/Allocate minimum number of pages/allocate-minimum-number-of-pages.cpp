//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int A[], int N, int M, int soln){
        int pageSum=0;//to store current sum of pages of books
        int c=1;// to update students
        
        for(int i=0; i<N; i++){
            // if pages of the first book is more than mid
            if(A[i]>soln){
            return false;
            }
            
            if(pageSum + A[i] > soln){
                c++;//goes to the next student
                pageSum=A[i]; // updating page sum
                
                if(c>M){
                    return false;
                }
            }
            else{
                //adding pages of the second book into current pageSum
                pageSum=pageSum + A[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        // no. of students is more than no. of books
        if (M > N){
            return -1;
        }
        int s=0;
        int e= accumulate(A, A+N, 0);
        int ans=0;
        int mid= s+(e-s)/2;
        
        while(s<=e){
            if(isPossible(A, N, M, mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid= s+(e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends