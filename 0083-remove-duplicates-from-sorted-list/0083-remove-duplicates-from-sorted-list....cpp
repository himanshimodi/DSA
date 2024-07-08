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
    ListNode* deleteDuplicates(ListNode* head) {
        //check if empty
        if(head == NULL){
            cout<<"LL is empty"<<endl;
            return head;
        }
        //single node
        if(head->next == NULL){
            cout<<"Single node in LL"<<endl;
            return head;
        }
        //more than one node
        ListNode* curr = head;
        while(curr!=NULL){
            if((curr->next != NULL) && (curr->val == curr->next->val)){
                //equal
                ListNode* temp = curr->next;
                curr->next = curr->next->next;

                //delete node
                temp->next = NULL;
                delete temp;
            }
            else{
                //not equal
                curr=curr->next;
            }
        }
        return head;
    }
};