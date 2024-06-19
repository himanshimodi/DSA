class Solution {
public:

    void helper(vector<int>& nums, vector<vector<int>>&ans, int i){

        //base case
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=i; j<nums.size(); j++){
            //swap
            swap(nums[i], nums[j]);
            //recursion
            helper(nums, ans, i+1);
            //backtracking
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, ans, 0);

        //to remove duplicate elements
        set<vector<int>> st;
        for(auto e:ans){
            st.insert(e);
        }
        ans.clear();
        for(auto e:st){
            ans.push_back(e);
        }
        return ans;
    }
};