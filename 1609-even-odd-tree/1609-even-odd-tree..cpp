class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == NULL) {
            return true; // Return true for an empty tree
        }

        queue<TreeNode*> q;
        q.push(root);
        bool even = true; // First level is an even level

        while (!q.empty()) {
            int size = q.size();
            int prev = even ? INT_MIN : INT_MAX; // Initialize prev based on the level

            while (size > 0) {
                TreeNode* frontNode = q.front();
                q.pop();

                // Conditions for even-indexed levels
                if (even && ((frontNode->val % 2 == 0) || (frontNode->val <= prev))) {
                    return false;
                }

                // Conditions for odd-indexed levels
                if (!even && ((frontNode->val % 2 == 1) || (frontNode->val >= prev))) {
                    return false;
                }

                prev = frontNode->val; // Update prev

                // Add child nodes to the queue
                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }

                size--;
            }
            even = !even; // Toggle even-odd level
        }
        return true;
    }
};
