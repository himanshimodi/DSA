class Solution {
public:
    int countPrimes(int n) {
        if(n==0) return 0;

        vector<bool> prime(n, true); //all are marked as prime in the start
        prime[0] = prime[1] = false; // 0 and 1 are always marked as false as they are not prime

        int ans=0; // this is a counter variable

        for(int i=2; i<n; i++){
            if(prime[i]){
                ans++;

                int j=2*i;
                while(j<n){
                    prime[j] = false;
                    j=j+i; // j is multiples of i, so all mutiples of i are marked as false
                }
            }
        }        
        return ans;
    }
};