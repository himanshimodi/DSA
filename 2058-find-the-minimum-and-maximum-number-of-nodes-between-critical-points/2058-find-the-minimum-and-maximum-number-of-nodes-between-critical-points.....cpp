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
    vector<int> nodesBetweenCriticalPoints(ListNode*& head) {
        vector<int> ans = {-1, -1}; // minDist, maxDist
        // LL is empty
        if (head == NULL)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = curr->next;

        // only one node is present
        if (curr == NULL)
            return ans;

        // only two nodes are present
        if (nxt == NULL)
            return ans;

        int i = 1; // initialising 'i' with the location of curr

        int firstCP = -1;
        int lastCP = -1;
        int minDist = INT_MAX;

        while (nxt != NULL) {
            // check if it is a critical point
            if ((curr->val > curr->next->val && curr->val > prev->val) ||
                (curr->val < curr->next->val && curr->val < prev->val)) {
                if (firstCP == -1) {
                    firstCP = i;
                    lastCP = i;
                } else {
                    minDist = min(minDist, i - lastCP);
                    lastCP = i;
                }
            }
            i++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }
        // only one CP is found
        if (lastCP == firstCP)
            return ans;
        else {
            ans[0] = minDist;
            ans[1] = lastCP - firstCP;
        }

        return ans;
    }
};