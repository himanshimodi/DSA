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
    int findLength(ListNode *&head){
        int len =0;
        ListNode *temp = head;

        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *&headA, ListNode *&headB) {
        if (headA==NULL || headB==NULL) return NULL;

        int lenA = findLength(headA);
        int lenB = findLength(headB);

        int diff = lenA>lenB ? lenA-lenB : lenB-lenA;

        ListNode *a = headA;
        ListNode *b = headB;

        for(int i=0; i<diff; i++){
            if(lenA>lenB){
                a= a->next;
            }
            else{
                b= b->next;
            }
        }
        
        while (a != NULL && b != NULL) {
            if (a == b) {
                return a;
            }
            a = a->next;
            b = b->next;
        }
        return NULL;
    }
};