class Solution {
public:
    // string removeDuplicates(string s) {
    //     string ans="";
    //     int i=0;

    //     while(i < s.length() ){

    //         if(ans.length() > 0){
    //              if( ans[ans.length()-1] == s[i] ) {
    //                 ans.pop_back();
    //             }
    //             else{
    //                 ans.push_back(s[i]);
    //             }
    //         }
    //         else {
    //             ans.push_back(s[i]);
    //         }
    //         i++;
    //     }
    //     return ans;
    // }


    //DONE USING STACK, THIS IS THE BEST POSSIBLE SOLUTION
    string removeDuplicates(string s){
        stack<char> st;
        for( int i=0; i<s.length();i++){
            if(!st.empty() && st.top() == s[i]){
                //if character is same as the top of the stack
                st.pop();
            }
            else{
                //if character is not same as the top of the stack
                st.push(s[i]);
            }
        }

            string ans;
            while(!st.empty()){
                ans+= st.top();
                st.pop();
            }

            reverse(ans.begin(), ans.end());
            return ans;
    }
};