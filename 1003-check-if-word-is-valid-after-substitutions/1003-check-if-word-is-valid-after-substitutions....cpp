class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char ch;
        int i=0;
        while(i<s.size()){
            ch = s[i];

            if(s[0] != 'a'){
                return false;
            }

            if(ch == 'a'){
                // if(st.empty()){
                    st.push(ch);
                // }
            }
            else if(ch =='b'){
                if(!st.empty() && st.top()=='a'){
                    st.push(ch);
                }
                else{
                    return false;
                }
            }
            if(ch =='c'){
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    if(!st.empty() && st.top()=='a'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                    
                }
                else{
                    return false;
                }
            }
            i++;
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};