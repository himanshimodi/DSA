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
    void preOrder(TreeNode* root, int temp, int &count){
        //BC
        if(root == NULL){
            return;
        }

        //ek case
        if(root->val >=temp){
            temp = root->val;
            count ++;
        }

        //RE
        preOrder(root->left,temp,count);
        preOrder(root->right,temp,count);
    }
    int goodNodes(TreeNode* root) {
        int temp = INT_MIN;
        int count=0;
        preOrder(root,temp,count);
        return count;
    }
};