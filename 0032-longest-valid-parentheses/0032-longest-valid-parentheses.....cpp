class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                st.push(i);
            } else {
                // if it is a closing bracket
                // step 1 : pop()
                st.pop();

                // step2 : check if empty
                if (st.empty()) {
                    st.push(i);
                } else {
                    // stack is not empty
                    int len = i - st.top();
                    maxLen = max(len, maxLen);
                }
            }
        }
        return maxLen;
    }
};