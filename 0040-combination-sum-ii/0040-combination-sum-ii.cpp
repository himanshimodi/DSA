class Solution {
public:
    void helper(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int target, int start) {
        // Base case
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // If the candidate is greater than the target, break the loop
            if (candidates[i] > target) {
                break;
            }

            // Include the current candidate in the combination
            combination.push_back(candidates[i]);

            // Recursively call helper with the next index and updated target
            helper(result, combination, candidates, target - candidates[i], i + 1);

            // Backtrack by removing the last added element
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;

        // Sort the candidates to handle duplicates
        sort(candidates.begin(), candidates.end());

        helper(result, combination, candidates, target, 0);

        return result;
    }
};
