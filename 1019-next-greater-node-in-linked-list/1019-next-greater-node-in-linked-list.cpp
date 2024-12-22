/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head = head->next;
        }
        vector<int>ans(v.size(),0);
        stack<int>st;
        st.push(0);

        for(int i=v.size()-1; i>=0;i--){
            int curr = v[i];
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(curr);
        }
        return ans;
    }
};