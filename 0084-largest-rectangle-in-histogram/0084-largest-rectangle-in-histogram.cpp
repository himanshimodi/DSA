class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Next smaller element index
        vector<int> nextSmaller(n, n);  // Default to n
        stack<int> st1;

        for (int i = n - 1; i >= 0; i--) {
            int curr = heights[i];
            while (!st1.empty() && heights[st1.top()] >= curr) {
                st1.pop();
            }
            if (!st1.empty()) {
                nextSmaller[i] = st1.top();
            }
            st1.push(i);
        }

        // Previous smaller element index
        vector<int> prevSmaller(n, -1);  // Default to -1
        stack<int> st2;

        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            while (!st2.empty() && heights[st2.top()] >= curr) {
                st2.pop();
            }
            if (!st2.empty()) {
                prevSmaller[i] = st2.top();
            }
            st2.push(i);
        }

        // Calculate max area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
