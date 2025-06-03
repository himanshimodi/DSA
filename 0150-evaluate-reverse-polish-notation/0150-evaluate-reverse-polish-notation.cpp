class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int finalans;
        stack<int>st;
        for(auto ch : tokens){
            if(ch=="+"){
                int first= st.top();
                st.pop();
                int second= st.top();
                st.pop();
                int currans = first + second;
                st.push(currans);
            }
            else if(ch=="-"){
                int first= st.top();
                st.pop();
                int second= st.top();
                st.pop();
                int currans = second - first;
                st.push(currans);
            }
            else if(ch=="*"){
                int first= st.top();
                st.pop();
                int second= st.top();
                st.pop();
                int currans = first * second;
                st.push(currans);
            }
            else if(ch=="/"){
                int first= st.top();
                st.pop();
                int second= st.top();
                st.pop();
                int currans = second / first;
                st.push(currans);
            }
            else{
                //a number
                int number = stoi(ch);
                st.push(number);
            }
        }
        finalans = st.top();
        st.pop();
        return finalans;
    }
};