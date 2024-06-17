class Solution {
public:

    void helper(vector<vector<int>> &result, vector<int>&combination, vector<int>& candidates, int target, int i){

        //base case
        if(target == 0){
            result.push_back(combination);
            return;
        }

        //base case
        if(target<0){
            return;
        }

        //ek case solve krdo
        for(int j=i; j<candidates.size();j++){
            combination.push_back(candidates[j]);
            //recursion
            helper(result, combination, candidates, target-candidates[j], j);
            //backtrack
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>combination;
        helper(result, combination, candidates, target, 0);

        return result;
    }
};