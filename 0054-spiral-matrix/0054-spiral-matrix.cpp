class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n= matrix[0].size();//column number
        int total_ele= m*n;

        int startRow=0;
        int endCol=n-1;
        int endRow=m-1;
        int startCol=0;

        int count=0;

        while(count<total_ele){
            //printing startRow
            for(int i=startCol;i<=endCol && count<total_ele;i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            //printing endCol
            for(int i=startRow;i<=endRow && count<total_ele;i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            //printing endRow
            for(int i=endCol;i>=startCol && count<total_ele;i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            //printing startCol
            for(int i=endRow;i>=startRow && count<total_ele;i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};