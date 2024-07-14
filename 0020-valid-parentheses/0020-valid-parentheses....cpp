class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                // closing bracket (ch is of input string)
                if (!st.empty()) {
                    char topCh = st.top();

                    // matching brackets
                    if (ch == ')' && topCh == '(') {
                        st.pop();
                    } else if (ch == '}' && topCh == '{') {
                        st.pop();
                    } else if (ch == ']' && topCh == '[') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if (st.empty()) {
            // valid
            return true;
        } else {
            return false;
        }
    }
};