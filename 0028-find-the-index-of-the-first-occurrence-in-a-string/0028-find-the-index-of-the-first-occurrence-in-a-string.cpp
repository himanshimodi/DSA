class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= haystack.size();
        int m= needle.size();

        if(haystack == needle){
            return 0;
        }
        // outer loop 
        for(int i=0; i<=n-m; i++){
            for(int j=0;j<m; j++){
                if(needle[j] != haystack[i+j] ){
                    break;
                }
                //entire needle is found 
                if(j == m-1){
                return i;
                }
            }
        }
        return -1;
    }
};