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

    int solveRE(TreeNode* &root){
        //BC
        if(root == NULL){
            return 0;
        }

        //ek case solve krdo
        int robAmt =0, dontRobAmt = 0;
        robAmt += root->val;
        if(root->left){
            robAmt+= solveRE(root->left->left) + solveRE(root->left->right);
        }
        if(root->right){
            robAmt+= solveRE(root->right->left) + solveRE(root->right->right);
        }
        dontRobAmt = solveRE(root->left) + solveRE(root->right);
        int ans = max(robAmt,dontRobAmt);
        return ans;
    }

    int solveMem(TreeNode* &root,unordered_map<TreeNode*, int>&dp){
        //BC
        if(root == NULL){
            return 0;
        }

        //step 3- if dp already exists
        if(dp.find(root)!=dp.end()){
            return dp[root];
        }

        //ek case solve krdo
        int robAmt =0, dontRobAmt = 0;
        robAmt += root->val;
        if(root->left){
            robAmt+= solveMem(root->left->left,dp) + solveMem(root->left->right,dp);
        }
        if(root->right){
            robAmt+= solveMem(root->right->left,dp) + solveMem(root->right->right,dp);
        }
        dontRobAmt = solveMem(root->left,dp) + solveMem(root->right,dp);
        dp[root] = max(robAmt,dontRobAmt);
        return dp[root];
    }

    //TABULATION NHI KR SAKTE BECAUSE CHILD NODE SE PARENT NODE ACCESS KRNA MUSHKIL HAI

    int rob(TreeNode* root) {

        // return solveRE(root);

        unordered_map<TreeNode*, int>dp;
        return solveMem(root,dp);
    }
};