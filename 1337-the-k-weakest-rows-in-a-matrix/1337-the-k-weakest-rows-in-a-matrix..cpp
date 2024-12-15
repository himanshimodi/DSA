class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(); //number of rows
        int m = mat[0].size(); //number of cols

        //pair-> {rowCount,rowNumber}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        vector<int>ans;

        for(int i=0;i<n;i++){
            int rowCount=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    rowCount++;
                }
                else{
                    break;
                }
            }
            minHeap.push({rowCount,i});
        }

        for(int i=0;i<k;i++){
            int rowNumber = minHeap.top().second;
            minHeap.pop();
            ans.push_back(rowNumber);
        }
        return ans;
    }
    
};