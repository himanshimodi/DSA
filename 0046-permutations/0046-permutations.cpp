class Solution {
public:
void permutation(vector<int> &nums, vector<vector<int>>&ans, int index)
{
    if(index== nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j=index; j<nums.size(); j++){
        swap(nums[index], nums[j]);
        permutation(nums,ans,index+1);
        swap(nums[index], nums[j]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        permutation(nums,ans,index);
        return ans;
    }
};