class Solution {
public:
    //WITH THE USE OF MAP
    void helper(vector<int>& nums, vector<vector<int>>&ans, int start){

        //base case
        if(start >= nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_map<int, bool> visited;
        for(int i=start; i<nums.size(); i++){
            if(visited.find(nums[i])!= visited.end()){
                continue;
            }
            visited[nums[i]] = true;
            //swap
            swap(nums[i], nums[start]);
            //recursion
            helper(nums, ans, start+1);
            //backtracking
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, ans, 0);

        return ans;
    }
};