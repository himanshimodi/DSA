class Solution {
public:
    bool isValid(int num) {
        //'a' and 'b' that we have found out should not contain 0 in their number
        while (num > 0) {
            if (num % 10 == 0) //finds out remainder
                return false;
            num /= 10; // finds out quotient
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (isValid(a) && isValid(b)) {
                return {a, b};
            }
        }
        return {}; //return NULL
    }
};