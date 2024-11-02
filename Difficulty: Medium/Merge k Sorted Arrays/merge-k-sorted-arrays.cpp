//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

class info{
    public:
    int data;
    int row;
    int col;
    info(int val, int r, int c){
        data = val;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(info *a, info *b){
        return a->data > b -> data;
    }
};



class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<info*, vector<info*>, compare>minHeap;
        
        for(int i = 0; i<arr.size(); i++){
            info* temp = new info(arr[i][0], i, 0);
            minHeap.push(temp);
        }
        
        vector<int>ans;
        
        while(!minHeap.empty()){
            info* temp = minHeap.top();
            int topElement = temp -> data;
            int topRow = temp -> row;
            int topCol = temp -> col;
            minHeap.pop();
            
            ans.push_back(topElement);
            
            if(topCol + 1 < arr[0].size()){
                info* newInfo = new info(arr[topRow][topCol+1], topRow, topCol+1);
                minHeap.push(newInfo);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends