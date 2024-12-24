class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char>st;
        for(char digit:num){
            if(k>0){
                while(!st.empty() && st.top()>digit){
                    st.pop();
                    k--;
                    if(k==0){
                        break;
                    }
                }
            }
            st.push(digit);
        }
        if(k>0){
            while(!st.empty()&& k>0){
                st.pop();
                k--;
            }
        }
        //k ab pakka zero hai
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        //removing end ke zeros
        while(ans.size()>0 && ans.back()=='0'){
            ans.pop_back();
        }

        reverse(ans.begin(),ans.end());
        return ans==""? "0": ans;
    }
};