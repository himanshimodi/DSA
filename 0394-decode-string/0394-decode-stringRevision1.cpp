#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (auto ch : s) {
            if (ch == ']') {
                // Extract the string to repeat
                string stringToRepeat = "";
                while (!st.empty() && st.top() != "[") {
                    string top = st.top();
                    // Fix the order of concatenation
                    stringToRepeat = top + stringToRepeat;  // Changed
                    st.pop();
                }               
                st.pop();  // Pop the '['
                
                // Extract the digits
                string numericTimes = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    string top = st.top();
                    // Fix the order of concatenation
                    numericTimes = top + numericTimes; // wont work with numericTimes += st.top()
                    st.pop();
                }
                
                int n = stoi(numericTimes);

                string currdecode = "";
                while (n--) {
                    currdecode += stringToRepeat;
                }
                st.push(currdecode);
            } else {
                string temp(1, ch);
                st.push(temp);
            }
        }

        // Decode the final string present in stack
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;  // Changed
            st.pop();
        }
        
        return ans;
    }
};