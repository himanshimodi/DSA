//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    bool isPossible(int A[], int n, int k, long long soln){
        long long timeSum=0; //to maintain current sum
        int c=1; 
        
        for(int i=0; i<n ; i++){
            //if first number of boards is more than mid
            if(A[i] > soln){
                return false;
            }
            if(timeSum + A[i] > soln){
                c++;
                timeSum=A[i];
                //if count exceeds number of painters
                if(c > k){
                    return false;
                }
            }
            else{
                timeSum += A[i];
            }
        }
        return true;
    }
    
    long long minTime(int A[], int n, int k)
    {
        long long s=0, ans=-1;
        long long e=0;
        for(int i=0; i<n ;i++){
            e+=A[i];
        }
        long long mid=s+(e-s)/2;
        
        //if no. of painters is more than no. of boards
        // if(k > n){
        //     return -1;
        // }
        
        while(s<=e){
            if(isPossible(A, n, k, mid)){
                ans=mid; // store ans as it is a possibility
                e=mid-1; // shrink our search space
            }
            else{
                s=mid + 1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends