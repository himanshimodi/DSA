class Solution {
public:
    bool checkValidString(string s) {
        stack<int>openBracket;
        stack<int>asterisks;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='('){
                openBracket.push(i);
            }
            else if( ch == '*'){
                asterisks.push(i);
            }
            else{
                //its a ) bracket
                if(!openBracket.empty()){
                    openBracket.pop();
                }
                else if(!asterisks.empty()){
                    asterisks.pop();
                }
                else{
                    //both stacks are empty
                    return false;
                }
            }
        }
        while(!openBracket.empty() && !asterisks.empty()){
            if(openBracket.top()>asterisks.top()){
                return false;
            }
            // else{
                openBracket.pop();
                asterisks.pop();
            // }
        }
        return openBracket.empty();;
    }
};