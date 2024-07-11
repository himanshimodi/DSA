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
    // Approach 1: TC= O(n^2)
    //  SC= O(1)
    ListNode* mergeNodes(ListNode*& head) {
        ListNode* mptr = new ListNode(-1);
        ListNode* ptr = mptr;
        ListNode* temp = head;

        temp = temp->next;
        int sum = 0;

        while (temp != NULL) {
            while (temp->val != NULL) {
                sum += temp->val;
                temp = temp->next;
            }
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            temp = temp->next;
            sum = 0;
        }
        return mptr->next;
    }
};