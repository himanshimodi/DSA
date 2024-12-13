class Solution {
public:
    bool checkBounds(vector<vector<int>>& grid, vector<pair<int, int>>& v) {
        int n = grid.size();
        int m = grid[0].size();
        for (auto pt : v) {
            if (pt.first < 0 || pt.first >= n || pt.second < 0 || pt.second >= m) {
                return false;
            }
        }
        return true;
    }

    bool getAllVertices(vector<vector<int>>& grid, vector<pair<int, int>>& v, pair<int, int> c, int delta) {
        pair<int, int> A(c.first - delta, c.second);
        pair<int, int> B(c.first, c.second + delta);
        pair<int, int> C(c.first + delta, c.second);
        pair<int, int> D(c.first, c.second - delta);

        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;

        return checkBounds(grid, v);
    }

    void getAllSum(vector<vector<int>>& grid, int cx, int cy, priority_queue<int>& pq) {
        pq.push(grid[cx][cy]);
        int delta = 1;
        vector<pair<int, int>> v(4);
        while (getAllVertices(grid, v, {cx, cy}, delta)) {
            pair<int, int>& A = v[0];
            pair<int, int>& B = v[1];
            pair<int, int>& C = v[2];
            pair<int, int>& D = v[3];

            int currSum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

            // Diagonal summation
            for (int i = 1; i < delta; i++) {
                currSum += grid[A.first + i][A.second + i];  // From A to B
                currSum += grid[B.first + i][B.second - i];  // From B to C
                currSum += grid[C.first - i][C.second - i];  // From C to D
                currSum += grid[D.first - i][D.second + i];  // From D to A
            }

            pq.push(currSum);
            ++delta;
        }
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        priority_queue<int> pq;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                getAllSum(grid, i, j, pq);
            }
        }

        // Extract top 3 distinct values
        unordered_set<int> seen;
        while (!pq.empty() && ans.size() < 3) {
            int top = pq.top();
            pq.pop();
            if (seen.find(top) == seen.end()) {
                ans.push_back(top);
                seen.insert(top);
            }
        }

        return ans;
    }
};
