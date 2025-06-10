class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //SLIDING WINDOW TECHNIQUE
        int len= INT_MAX;
        int s=0;
        int e=0;
        int sum =0;

        while(e<nums.size()){ //variable size window is used
            sum+=nums[e];
            while(sum>=target){
                len = min(len,e-s+1);
                sum-=nums[s];
                s++;
            }
            e++;
        }

        if(len == INT_MAX){
            return 0;
        }
        else{
            return len;
        }
    }
};