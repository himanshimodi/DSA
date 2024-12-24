class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char>st;
        int count=0;
        for(char ch:s){
            if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                    count++;
                }
            }
        }
        return count;
    }
};