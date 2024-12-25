class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> queue;
        queue.push(root);

        if (root == NULL) {
            return ans;
        }
                
        while (!queue.empty()) {
            int currLen = queue.size();
            int currMax = INT_MIN;
            
            for (int i = 0; i < currLen; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                currMax = max(currMax, node->val);
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }  
            ans.push_back(currMax);
        } 
        return ans;
    }
};