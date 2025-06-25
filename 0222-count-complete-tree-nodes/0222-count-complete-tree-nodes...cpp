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
    int leftHeight(TreeNode* root){
        int c=1;
        while(root->left != NULL){
            c++;
            root= root->left;
        }
        return c;
    }

    int rightHeight(TreeNode* root){
        int c=1;
        while(root->right != NULL){
            c++;
            root= root->right;
        }
        return c;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }   
        if(root->left == NULL && root->right==NULL){
            return 1;
        }

        int lh = leftHeight(root);
        int rh = rightHeight(root);
        int nodes;

        if(lh==rh){
            nodes = (1<<lh)-1; //2^height-1
        }
        else{
            nodes = 1+countNodes(root->left)+countNodes(root->right);
        }
        return nodes;

    }
};