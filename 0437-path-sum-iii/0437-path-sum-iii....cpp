/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPaths(TreeNode* root, long long currSum, int targetSum, unordered_map<long long, int>& map) {
        //BC
        if (root == NULL) {
            return 0;
        }
        currSum += root->val;
        
        int numPaths = map[currSum - targetSum];
        map[currSum]++;
        
        numPaths += countPaths(root->left, currSum, targetSum, map);
        numPaths += countPaths(root->right, currSum, targetSum, map);
        
        map[currSum]--;
        return numPaths;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> map;
        map[0] = 1;
        
        return countPaths(root, 0, targetSum, map);
    }
};
