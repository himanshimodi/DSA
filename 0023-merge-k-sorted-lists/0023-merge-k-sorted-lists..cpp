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

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        //process first k elements
        //har list ka pehla element pq mai insert krna hai
        int totalRows = lists.size();

        for(int row=0; row<totalRows; row++){
            ListNode* temp = lists[row];
            if(temp != NULL){
                //valid node hai
                pq.push(temp);
            }
        }

        //main logic
        while(!pq.empty()){
            ListNode* front = pq.top();
            pq.pop();
            //ans mai insert kro
            if(head == NULL&& tail == NULL){
                //means inserting first node in LL
                head = front;
                tail = front;
            }
            else{
                //this is not the first node
                tail->next = front;
                tail = tail->next;
            }

            //if more nodes are present then insert in pq
            if(tail->next != NULL){
                pq.push(tail->next);
            }
        }
        return head;
    }
};