class Solution {
public:
    // gets my work done in seconds but we have to implement what "s.c_str()" 
    // this function does
    // int myAtoi(string s) {
    //     int integer = atoi(s.c_str());
    //     return integer;
    // }
    int myAtoi(string s){
        int num=0;
        int i=0;
        int sign = 1; //assuming the given string has a positive integer

        //step 1: ignore if whitespace 
        while(s[i] == ' '){
            i++;
        }
        //step 2: check the sign 
        if(i<s.size() && (s[i] == '+' || s[i] == '-')){
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }
        //step 3: check if it is a digit
        while(i < s.size() && isdigit(s[i])){
            int digit = s[i] - '0'; //s[i]-'0' converts s[i](char) into integer
            if (num > (INT_MAX - digit) / 10) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + digit;
            i++;
        }
        return num * sign;
    }
};