/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Approach 1: TC = O(n)
    //  SC = O(n) because of the elements in map which are stored in stack memory
    // check for Approach 2 in another file

    Node* helper(Node* head, unordered_map<Node*, Node*>& map) {

        if (head == NULL)
            return NULL;

        Node* newHead = new Node(head->val);
        map[head] = newHead;
        newHead->next = helper(head->next, map);

        if (head->random != NULL) {
            newHead->random = map[head->random];
        }
        return newHead;
    }
    Node* copyRandomList(Node*& head) {
        unordered_map<Node*, Node*>
            map; //  connecting old LL elements to new LL elements
        return helper(head, map);
    }
};