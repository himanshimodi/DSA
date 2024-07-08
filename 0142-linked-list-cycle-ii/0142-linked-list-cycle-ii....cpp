/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL; // No cycle if the list is empty or has only one node
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast= fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(slow == fast){
                slow = head;
                break;
            }
        }
        if (fast == NULL || fast->next == NULL) {
            return NULL; // No cycle found
        }
        while(slow!= fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};