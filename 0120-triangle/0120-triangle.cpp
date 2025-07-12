class Solution {
public:
    int solveRE(vector<vector<int>>& triangle, int n, int row, int col){
        //BC
        if(row == n-1){
            return triangle[row][col];
        }

        //ek case
        int lower_left = triangle[row][col] + solveRE(triangle,n,row+1,col);
        int lower_right = triangle[row][col] + solveRE(triangle,n,row+1,col+1);

        return min(lower_left,lower_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return solveRE(triangle,n,0,0);
    }
};