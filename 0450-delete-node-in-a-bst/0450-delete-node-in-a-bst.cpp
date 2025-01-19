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
    int maxValue(TreeNode* root){
        if(root == NULL){
            return -1;
        }
        while(root->right!=NULL){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //BC
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            //4 cases
            //1st case: leaf node
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left != NULL && root->right == NULL){
                //2nd case:only left is null
                TreeNode* childSubtree = root->left;
                delete root;
                return childSubtree;
            }
            else if(root->left == NULL && root->right !=NULL){
                //3rd case:only right is null
                TreeNode* childSubtree = root->right;
                delete root;
                return childSubtree;
            }
            else{
                //4th case: both not null
                //left subtree ki max value lao
                int maxi = maxValue(root->left);
                root->val = maxi;
                //delete actual node from bst
                root->left = deleteNode(root->left,maxi);
                return root;
            }
        }
        else if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};