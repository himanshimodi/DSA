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

    void inorderTraversal(TreeNode* root, vector<int>&inorder){
        if(root == NULL) return;
        //LNR
        inorderTraversal(root->left, inorder);
        //N
        inorder.push_back(root->val);
        //R
        inorderTraversal(root->right, inorder);
    }

    TreeNode* build(vector<int>&inorder, int s, int e){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = build(inorder, s, mid-1);
        root->right = build(inorder, mid+1, e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        inorderTraversal(root, inorder);
        //build balanced bst using inorder traversal
        int s =0;
        int e = inorder.size()-1;
        return build(inorder,s,e);
    }
};