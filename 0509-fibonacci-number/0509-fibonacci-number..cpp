class Solution {
public:
    int fib(int n) {
        //base case
        if(n==1){
            return 1;
        }
        else if(n==0){
            return 0;
        }
        int ans =0;
        ans = fib(n-1)+ fib(n-2);
        return ans;
    }
};