class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int longestWindow = 0;
        int start = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0){
                zeroCount++;
            }
            // Shrink the window until the count of zero's
            // is less than or equal to 1.
            while (zeroCount > 1) {
                if(nums[start]==0){
                    zeroCount--;
                }
                start++;
            }
            longestWindow = max(longestWindow, i - start);
        }
        return longestWindow;
    }
};