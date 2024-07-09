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
    ListNode* mergeTwoLists(ListNode* &head1, ListNode* &head2) {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val <= head2->val) {
                mptr->next = head1;
                mptr = head1;
                head1 = head1->next;
            } else {
                mptr->next = head2;
                mptr = head2;
                head2 = head2->next;
            }
        }
        if (head1 == NULL) {
            mptr->next = head2;
        }
        if (head2 == NULL) {
            mptr->next = head1;
        }

        return ans->next;
    }
};