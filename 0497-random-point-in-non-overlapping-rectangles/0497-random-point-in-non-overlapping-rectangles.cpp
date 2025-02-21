class Solution {
public:
    int n;                        // Number of rectangles
    vector<int> prefixAreas;       // Prefix sum of rectangle areas
    vector<vector<int>> rects;     // List of rectangles

    // Function to calculate the number of points in a rectangle
    int computeArea(vector<int> &rect) {
        int width = rect[2] - rect[0] + 1;   // (x2 - x1 + 1)
        int height = rect[3] - rect[1] + 1;  // (y2 - y1 + 1)
        return width * height;
    }

    // Constructor: Precompute prefix sums for weighted random selection
    Solution(vector<vector<int>>& _rects) {
        rects = _rects;
        n = rects.size();
        prefixAreas.resize(n);

        // Compute prefix sum of rectangle areas
        prefixAreas[0] = computeArea(rects[0]);
        for (int i = 1; i < n; i++) {
            prefixAreas[i] = prefixAreas[i - 1] + computeArea(rects[i]);
        }
    }

    // Function to pick a random point uniformly across all rectangles
    vector<int> pick() {
        // Step 1: Choose a random point index from the total points
        int randPointIndex = rand() % prefixAreas[n - 1];

        // Step 2: Find the rectangle that contains this point
        int rectIdx = lower_bound(prefixAreas.begin(), prefixAreas.end(), randPointIndex + 1) - prefixAreas.begin();

        // Step 3: Adjust the random index relative to the chosen rectangle
        if (rectIdx > 0) {
            randPointIndex -= prefixAreas[rectIdx - 1];
        }

        // Step 4: Compute the coordinates of the random point inside the selected rectangle
        int x1 = rects[rectIdx][0], y1 = rects[rectIdx][1];
        int x2 = rects[rectIdx][2], y2 = rects[rectIdx][3];

        int width = x2 - x1 + 1;  // Number of columns in the rectangle

        int randomX = x1 + (randPointIndex % width);
        int randomY = y1 + (randPointIndex / width);

        return {randomX, randomY};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
