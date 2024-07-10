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
    // TC = O(N) and SC = O(1)
    ListNode* findNthNode(ListNode*& head, int k) {
        int count = 1; // 1 based indexing
        while (head != NULL) {
            if (count == k) return head;
            count++;
            head = head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || k == 0) return head;
        ListNode* tail = head;

        // now we simply find length
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        if (k % len == 0) return head; 

        int actualRotateK = k % len;
        tail->next = head;
        ListNode* newLastNode = findNthNode(head, len - actualRotateK);
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};