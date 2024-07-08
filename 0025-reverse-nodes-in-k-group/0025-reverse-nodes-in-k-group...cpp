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
    int findLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head; // If the list is empty or has only one node, return as is
        }

        int len = findLength(head);

        if (k > len) {
            return head; // If k is greater than the length of the list, return the original list
        }

        // Step 1: Reverse k nodes of the list
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        int count = 0;

        while (count < k && curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // Step 2: Recursive call to reverse the remaining nodes
        if (nextNode != NULL) {
            head->next = reverseKGroup(nextNode, k);
        }

        // Step 3: Return the head of the modified list
        return prev;
    }
};
