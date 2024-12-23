class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int>st;
        int j=0;
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            while(j<=n && !st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};