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
    // Helper function to count paths with sum equal to targetSum starting from the current node
    int number(TreeNode* root, long long int currsum, int targetSum) {
        if (root == NULL) return 0;
        
        currsum += root->val;
        
        int ans = 0;
        
        if (targetSum == currsum) ans++;
        
        return ans + number(root->left, currsum, targetSum) + number(root->right, currsum, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        
        return number(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};