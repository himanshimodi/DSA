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
    // // Approach 1: TC= O(n^2)
    // //  SC= O(1)
    // ListNode* mergeNodes(ListNode*& head) {
    //     ListNode* mptr = new ListNode(-1);
    //     ListNode* ptr = mptr;
    //     ListNode* temp = head;

    //     temp = temp->next;
    //     int sum = 0;

    //     while (temp != NULL) {
    //         while (temp->val != NULL) {
    //             sum += temp->val;
    //             temp = temp->next;
    //         }
    //         ptr->next = new ListNode(sum);
    //         ptr = ptr->next;
    //         temp = temp->next;
    //         sum = 0;
    //     }
    //     return mptr->next;
    // }

    // Approach2: TC=O(n)
    // SC = O(1)
    // Here we are deleting nodes so that process takes more time so TC is low
    ListNode* mergeNodes(ListNode*& head) {
        if (head == NULL)
            return NULL;

        ListNode *slow = head, *fast = head->next;
        ListNode* newLastNode = NULL;
        int sum = 0;

        while (fast != NULL) {
            if (fast->val != 0) {
                sum += fast->val;
            } else {
                slow->val = sum;
                newLastNode = slow;
                slow = slow->next;
                sum = 0;
            }
            fast = fast->next;
        }

        ListNode* temp = newLastNode->next;
        newLastNode->next = NULL;

        // deleting old LL
        while (temp != NULL) {
            ListNode* ptr = temp->next;
            delete temp;
            temp = ptr;
        }
        return head;
    }
};