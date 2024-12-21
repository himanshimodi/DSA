class Solution {
public:
    vector<int> prevSmallerElement(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        // left to right
        for (int i = 0; i < input.size(); i++) {
            int curr = input[i];

            // put ans in stack, input[s.top()]->coz we want to access the index
            while (s.top() != -1 && input[s.top()] >= curr) {
                s.pop();
            }

            // chota element mil chuka hai toh store ans
            ans[i] = s.top();

            // push krdo curr element ko
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        // left to right
        for (int i = input.size() - 1; i >= 0; i--) {
            int curr = input[i];

            // put ans in stack, input[s.top()]->coz we want to access the index
            while (s.top() != -1 && input[s.top()] >= curr) {
                s.pop();
            }

            // chota element mil chuka hai toh store ans
            ans[i] = s.top();

            // push krdo curr element ko
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {

        // step 1: Prev Smaller output
        vector<int> prev = prevSmallerElement(heights);

        // step 2: nextSmaller output
        vector<int> next = nextSmaller(heights);

        int maxArea = INT_MIN;
        int size = heights.size();

        for (int i = 0; i < heights.size(); i++) {
            int len = heights[i];

            if (next[i] == -1) {
                next[i] = size;
            }

            int width = next[i] - prev[i] - 1;

            int area = len * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};