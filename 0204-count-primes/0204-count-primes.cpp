class Solution {
public:
    int countPrimes(int n) {
        if(n==0) return 0;

        vector<bool> prime(n, true); //all are marked as prime in the start
        prime[0] = prime[1] = false; // 0 and 1 are always marked as false as they are not prime
        
        int ans=0;

        for(int i=2; i<n; i++){
            if((i%2)==0){
                prime[i] = false; // i is in the table of 2
                ans++;
            }
        }        
        return ans;
    }
};