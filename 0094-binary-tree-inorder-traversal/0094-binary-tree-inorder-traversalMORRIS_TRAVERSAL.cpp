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
    //MORRIS TRAVERSAL: TC=O(N) AND SC=O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr){
            //if left is null, visit it and go right
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                //left is not null, so find inorder predecessor
                TreeNode* pred = curr->left;
                while( pred->right && pred->right != curr){
                    pred = pred->right;
                }
                //if pred->right is null, make a link from pred to curr
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    //if curr->left is already visited, go right and break link from pred to curr
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};