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

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

ListNode* reverse(ListNode*& head) {
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode*& head1, ListNode*& head2) {

        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;

        while (head1 != NULL && head2 != NULL) {
            // calculate sum
            int sum = carry + head1->val + head2->val;

            // find digit to create node
            int digit = sum % 10;

            // calculate carry
            carry = sum / 10;

            // create new node for the digit
            ListNode* newNode = new ListNode(digit);

            // attach new node to the ans wali LL
            if (ansHead == NULL) {
                // inserting first node
                ansHead = newNode;
                ansTail = newNode;
            } else {
                ansTail->next = newNode;
                ansTail = newNode;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        // when length of head1 LL > head2 LL
        while (head1 != NULL) {
            int sum = carry + head1->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            head1 = head1->next;
        }

        // when length of head2 LL > head1 LL
        while (head2 != NULL) {
            int sum = carry + head2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            head2 = head2->next;
        }

        // carry ko alag se handle kro
        while (carry != 0) {
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
        }
        return ansHead;
    }
};

