/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TC- O(depth of BST)
        //BC
        if(root == NULL) return NULL;

        //case 1- pand q both are in LST
        if(p->val<root->val && q->val <root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left, p,q);
            return leftAns;
        }

        //case 2- p and q both are in RST
        if(p->val>root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right, p,q);
            return rightAns;
        }

        // //case 3- p is in LST and q is in RST
        // if(p->val < root->val && q->val > root->val){
        //     return root;
        // }

        // //case 4 - q is in LST and p is in RST
        // if(q->val < root->val && p->val > root->val){
        //     return root;
        // }
        return root;
    }
};