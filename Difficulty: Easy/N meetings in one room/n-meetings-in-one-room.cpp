//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    static bool cmp(pair<int,int>a, pair<int,int>b){
        return a.second<b.second;
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> time;
        for(int i=0; i<start.size();i++){
            time.push_back({start[i],end[i]});
        }
        
        sort(time.begin(),time.end(),cmp);
        
        //first meeting toh include krni he hai
        int c=1;
        int prevStart = time[0].first;
        int prevEnd = time[0].second;
        
        for(int i=0; i<start.size();i++){
            int currStart = time[i].first;
            int currEnd = time[i].second;
            
            if(prevEnd<currStart){
                //include kr sakte hai
                c++;
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends