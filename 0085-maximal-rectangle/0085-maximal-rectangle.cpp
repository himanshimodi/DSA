class Solution {
    public: // first 3 functions are a part of largestRectangleArea - leetcode 84
    vector<int> prevSmallerElement(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        // left to right
        for (int i = 0; i < input.size(); i++) {
            int curr = input[i];

            // put ans in stack
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

            // put ans in stack
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            vector<int> t;
            for(int j=0; j<m; j++){
                t.push_back(matrix[i][j]-'0'); //convert into an integer
            }
            v.push_back(t);
        }

        int area = largestRectangleArea(v[0]);
        for( int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]){
                    v[i][j]+= v[i-1][j];
                }
                else{
                    v[i][j]=0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};