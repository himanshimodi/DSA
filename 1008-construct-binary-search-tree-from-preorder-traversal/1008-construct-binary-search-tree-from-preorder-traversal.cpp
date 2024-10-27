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

    TreeNode* create(int &i, int min, int max, vector<int>&preorder){
        if(i>=preorder.size()){
            return NULL;
        }
        TreeNode* root = NULL;
        //NLR
        if(preorder[i]>min && preorder[i]<max){
            //toh ye range mai hai
            root = new TreeNode(preorder[i]);
            i++;
            root->left = create(i,min,root->val,preorder);
            root->right = create(i,root->val,max,preorder);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN, max = INT_MAX;
        int i = 0;
        return create(i,min,max,preorder);
    }
};