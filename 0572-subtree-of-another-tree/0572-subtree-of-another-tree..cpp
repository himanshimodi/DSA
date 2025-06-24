class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }

        if(p!=NULL && q!=NULL){
            if(p->val == q->val){
                return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
            }
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;       // An empty tree is always a subtree
        if(root == NULL) return false;         // Non-empty subtree can't match null root

        if(isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};