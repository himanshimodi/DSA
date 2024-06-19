class Solution {
public:
    void helper(vector<int>& v, int &n, int &ans, int currNum) {
        // base case
        if (currNum >= n + 1) {
            ++ans;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (v[i] == 0 && ((currNum % i == 0) || (i % currNum == 0))) {
                // ek case solve krdo
                v[i] = currNum;
                // Recursion
                helper(v, n, ans, currNum + 1);
                // backtracking
                v[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n + 1); // initialising with n+1

        int ans = 0;
        helper(v, n, ans, 1);

        return ans;
    }
};