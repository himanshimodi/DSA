class NumMatrix {
    vector<vector<int>> ps; 
public:
    NumMatrix(vector<vector<int>>& mt) {
        int n = mt.size();
        int m = mt[0].size();
        ps.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ps[i][j] = mt[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, col1++, row2++, col2++; 
        return ps[row2][col2] - ps[row1 - 1][col2] - ps[row2][col1 - 1] + ps[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */