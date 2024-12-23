class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>record;
        int sum=0;
        stack<int>st;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                st.pop();
            }
            else if(ops[i]=="D"){
                int top = st.top();
                int newtop = top*2;
                st.push(newtop);
            }
            else if(ops[i]=="+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int calc = first+second;
                st.push(second);
                st.push(first);
                st.push(calc);
            }
            else{
                //its a digit
                st.push(stoi(ops[i]));
            }
        }
        while(!st.empty()){
            record.push_back(st.top());
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};