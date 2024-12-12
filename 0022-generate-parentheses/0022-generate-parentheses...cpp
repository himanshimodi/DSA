class Solution {
public:
    vector<string> solve(vector<string>& ans, string &output, int open, int close, int n) {
        // BC
        if (open == n && close == n) {
            ans.push_back(output);
            return ans;
        }

        if (open < n) {
            output.push_back('(');
            solve(ans, output, open + 1, close, n);
            output.pop_back(); //backtrack
        }

        if (close < open) {
            output.push_back(')');
            solve(ans, output, open, close + 1, n);
            output.pop_back(); //backtrack
        }
        return ans;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        int open = 0, close = 0;
        ans = solve(ans, output, open, close, n);
        return ans;
    }
};