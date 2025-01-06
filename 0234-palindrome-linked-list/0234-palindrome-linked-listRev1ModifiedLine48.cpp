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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            cout << "LL is empty" << endl;
            return true;
        }
        if (head->next == NULL) {
            return true;
        }
        // more than one node so find middle node
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        // slow pointer is pointing to the middle node
        // now reverse
        ListNode* reverseLLkaHead = reverse(slow->next);
        // slow = slow->next;

        // start comparison
        ListNode* temp1 = head;
        ListNode* temp2 = reverseLLkaHead;

        while (temp2 != NULL) {
            if (temp1->val != temp2->val) {
                return false;
            } else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }
};