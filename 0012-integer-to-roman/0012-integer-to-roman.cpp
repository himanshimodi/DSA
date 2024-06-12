class Solution {
public:
    //int to roman.....
    string intToRoman(int num) {
    string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int value[] ={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string ans="";
    int i=0;
    for(int i=0;i<13;i++){
        while(num>=value[i]){
        ans += romanSymbols[i];
        num -= value[i];
        }
    }
    
    return ans;
    
    }
};