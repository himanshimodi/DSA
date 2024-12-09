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

    vector<TreeNode*> solveRE(int n, int s, int e){
        //BC
        if(n<=1){
            TreeNode* temp = new TreeNode(s);
            return {temp};
        }
        if(s>e){
            return {0};
        }
        
        //ek case solve krdo
        vector<TreeNode*>ans;
        for(int i=s;i<=e;i++){
            vector<TreeNode*>left = solveRE(n,s,i-1);
            vector<TreeNode*>right = solveRE(n,i+1,e);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solveRE(n,1,n);
    }
};