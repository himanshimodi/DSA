class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans;
        priority_queue<int>maxHeap;

        int rows=matrix.size();
        int cols=matrix[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int ele = matrix[i][j];
                maxHeap.push(ele);
                if(maxHeap.size()>k){
                    maxHeap.pop();
                }
            }
        }
        return maxHeap.top();
    }
};