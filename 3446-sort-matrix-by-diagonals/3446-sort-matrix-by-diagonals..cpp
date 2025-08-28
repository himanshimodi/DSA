class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        //column based diagonals
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; i + j < n; j++) {
                tmp.push_back(grid[i + j][j]);
            }
            sort(tmp.begin(), tmp.end(), greater<int>()); //descending order
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = tmp[j];//replace
            }
        }

        //row based diagonals
        for (int j = 1; j < n; j++) {
            vector<int> tmp;
            for (int i = 0; j + i < n; i++) {
                tmp.push_back(grid[i][j + i]);
            }
            sort(tmp.begin(), tmp.end()); //ascending order
            for (int i = 0; j + i < n; i++) {
                grid[i][j + i] = tmp[i];//replace
            }
        }
        return grid;
    }
};