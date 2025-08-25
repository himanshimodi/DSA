class Solution {
public:
    // row+col = 0 → {1}

    // row+col = 1 → {2, 4}

    // row+col = 2 → {3, 5, 7}

    // row+col = 3 → {6, 8}

    // row+col = 4 → {9}

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty())
            return {};
        int m = mat.size(), n = mat[0].size();

        unordered_map<int, vector<int>> mp; // key = row+col
        vector<int> result;
        result.reserve(m * n);

        // Group elements by diagonals
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        // Collect diagonals in the right order
        for (int d = 0; d <= m + n - 2; d++) {
            if (d % 2 == 0) {
                // reverse for even diagonals
                reverse(mp[d].begin(), mp[d].end());
            }
            for (int val : mp[d]) {
                result.push_back(val);
            }
        }

        return result;
    }
};