//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    //first create the mask and then create a subsequence
		    int len = s.length();
		    int n = (1<<len);
		    vector<string> ans;
		    for(int num =0; num<n;num++){
		        string temp="";
		        for(int i=0; i<len; i++){
		            char ch = s[i];
		            int mask = (1<<i);
		            if(num & mask){
		                //include the character because the mask is 1
		                temp.push_back(ch);
		            }
		        }
		        if(temp.length()>0){
		            ans.push_back(temp);
		        }
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends