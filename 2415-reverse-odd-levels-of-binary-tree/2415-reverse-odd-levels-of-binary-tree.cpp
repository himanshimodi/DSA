class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return NULL;  
        }

        queue<TreeNode*> q;
        q.push(root);  // Start BFS with the root node
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> currentLevelNodes;

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelNodes.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse node values if the current level is odd
            if (level % 2 == 1) {
                int left = 0, right = currentLevelNodes.size() - 1;
                while (left < right) {
                    int temp = currentLevelNodes[left]->val;
                    currentLevelNodes[left]->val =
                        currentLevelNodes[right]->val;
                    currentLevelNodes[right]->val = temp;
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root; 
    }
};