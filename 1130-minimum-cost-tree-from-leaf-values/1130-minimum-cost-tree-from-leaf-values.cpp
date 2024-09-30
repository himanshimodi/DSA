class Solution {
public:

    int solveUsingRe(vector<int>&arr, map<pair<int,int>, int>&maxi, int s, int e){
        //base case
        if(s>=e){
            return 0;
        }

        int ans = INT_MAX;
        //for partitioning
        for(int i=s; i<e; i++){
            ans = min(ans, (maxi[{s,i}]* maxi[{i+1, e}]) 
                            + solveUsingRe(arr,maxi,s,i)
                            + solveUsingRe(arr,maxi,i+1,e));
        }
        return ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        //pre computation
        map<pair<int,int>,int> maxi;
        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        int n= arr.size();
        int start =0;
        int end = n-1;
        int ans = solveUsingRe(arr,maxi,start,end);
        return ans;
    }
};