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
    TreeNode * FV =0, *SV=0, *prev =0;
    void solve(TreeNode*curr){
        if(curr==NULL) return;
        //inorder - LNR
        solve(curr->left);

        // N - store & compute
        if(prev && curr->val < prev->val){
            // property is violated
            if(FV == NULL){
                FV= prev;
            }
            SV = curr;
        }
        prev = curr;

        //R
        solve(curr->right);
    }

    void recoverTree(TreeNode* root) {
        solve(root);
        if(FV && SV){
            swap(FV->val, SV->val);
        }  
    }
};