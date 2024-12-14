class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(); //no. of rows
        int m = mat[0].size(); //no. of cols

        priority_queue<int>maxHeap1;

        for(int i=0;i<m;i++){
            maxHeap1.push(mat[0][i]); //all elements of 1st row
        }

        for(int i=1;i<n;i++){
            priority_queue<int>maxHeap2;
            while(!maxHeap1.empty()){
                int top = maxHeap1.top();
                maxHeap1.pop();

                for(int j=0;j<m;j++){
                    int num=top+mat[i][j];
                    if(maxHeap2.size()<k){
                        maxHeap2.push(num);
                    }
                    else{
                        if(num<maxHeap2.top()){
                            maxHeap2.pop();
                            maxHeap2.push(num);
                        }
                    }
                }
            }
            maxHeap1 = maxHeap2;
        }
        return maxHeap1.top();
    }
};