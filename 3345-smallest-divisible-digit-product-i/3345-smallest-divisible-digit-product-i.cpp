class Solution {
public:
    int smallestNumber(int n, int t) {
        int smallest = n;

        while (true) {
            int prod = 1, temp = smallest;

            while (temp > 0) {
                prod *= temp % 10;
                temp /= 10;
            }

            if (prod % t == 0) {
                return smallest;
            }

            smallest++;
        }
    }
};
