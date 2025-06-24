/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void makeMap(TreeNode* root,unordered_map<TreeNode*, TreeNode*>&parentMap){
        if(root == NULL){
            return;
        }

        if(root->left != NULL){
            parentMap[root->left]= root;
            makeMap(root->left,parentMap);
        }
        if(root->right != NULL){
            parentMap[root->right]= root;
            makeMap(root->right,parentMap);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL || target == NULL){
            return {};
        }

        unordered_map<TreeNode*, TreeNode*>parentMap; //child,parent
        parentMap[root] = NULL;
        makeMap(root,parentMap);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]= true;

        int currLevel =0;
        while(!q.empty()){
            int size = q.size();
            if(currLevel == k){
                break;
            }

            currLevel++;
            //Traverse all the nodes at the current level
            for(int i=0;i<size;i++){
                auto front = q.front();
                q.pop();

                if(front->left != NULL && visited.find(front->left)==visited.end()){
                    //front ka left exists and has not been visited yet
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right != NULL && visited.find(front->right)==visited.end()){
                    //front ka right exists and has not been visited yet
                    q.push(front->right);
                    visited[front->right]=true;
                }

                auto parentOfFront = parentMap[front];
                if(parentOfFront != NULL && visited.find(parentOfFront)== visited.end()){
                    q.push(parentOfFront);
                    visited[parentOfFront]= true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};