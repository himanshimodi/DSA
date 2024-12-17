class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }

        bool ans_sign = true; //true meaning positive here
        if(dividend>0 && divisor<0){
            ans_sign = false;
        }
        if(dividend<0 && divisor>0){
            ans_sign = false;
        }

        long long int newDividend = abs((long long)dividend);
        long long int newDivisor = abs((long long)divisor);
        long long int s=0, e=newDividend;
        long long int ans =0;

        while(s<=e){
            long long mid = s+(e-s)/2;
            if(mid*newDivisor <= newDividend){
                ans = mid;
                s=mid+1;
            }
            else{
                e = mid-1;
            }
        }
        if(ans_sign == false){
            return -ans;
        }
        return ans;

    }
};