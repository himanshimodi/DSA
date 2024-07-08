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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false; // No cycle if the list is empty or has only one node
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
                //loop is present
                return true;
            }
        }

        //loop is absent
        return false;
    }
};