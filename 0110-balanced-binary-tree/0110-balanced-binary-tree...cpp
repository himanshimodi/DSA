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
    int height(TreeNode* root){
        //base case
        if(root==NULL){
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int finalHeight = max(leftHeight, rightHeight)+1;
        return finalHeight;
    }
    bool isBalanced(TreeNode* root) {
        //in boolean 0 = false and 1 = true
        //base case
        if(root==NULL){
            return true;
        }

        //ek case solve krdo
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight-rightHeight);
        bool currNodeAns=false;
        if(diff<=1){
            currNodeAns = true;
        }
        else{
            currNodeAns = false;
        }

        if(currNodeAns && leftAns && rightAns){
            return true;
        }
        else{
            return false;
        }
    }
};