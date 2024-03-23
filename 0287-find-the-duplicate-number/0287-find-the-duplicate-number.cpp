class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //this is my 3rd approach
        while(nums[0]!= nums[nums[0]]){
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};