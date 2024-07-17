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
        vector<int> v;
        

        // Extract values from the linked list into the vector 'v'
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }

        // Initialize the answer vector with zeros
        vector<int> ans(v.size());

        stack<int> st;
        for (int i = v.size() - 1; i >= 0; i--) {
            int curr = v[i];

            // Maintain elements in the stack in decreasing order
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // If stack is not empty, the top element is the next greater element
            if (!st.empty()) {
                ans[i] = st.top();
            }

            // Push the current element onto the stack
            st.push(curr);
        }

        return ans;
    }
};
