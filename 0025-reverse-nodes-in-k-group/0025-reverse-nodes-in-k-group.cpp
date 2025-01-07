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
    int findLen(ListNode*& head){
        ListNode* temp = head;
        int count =0;

        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        int totalLen = findLen(head);
        if(totalLen < k){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextnode = NULL;
        int c =0;

        while(curr!=NULL && c<k){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr= nextnode;
            c++;
        }

        //RE
        if(nextnode!=NULL){
            head->next = reverseKGroup(nextnode,k);
        }
        return prev;
    }
};