class Solution {                      
public:
    int reverse(int x) {
        int r=0;      // decleare r 
        while(x){
         if (r>INT_MAX || r<INT_MIN) return 0; // check 32 bit range 
         r=r*10+x%10; // find remainder and add its to r
         x=x/10;     // Update the value of x
        } 
        return r;  // if r in the 32 bit range then return r
    }
}; 