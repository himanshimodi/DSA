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
    // // Approach 1: TC = O(n)
    // //  SC = O(n) because of the elements in map which are stored in stack
    // memory
    // // check for Approach 2 in another file

    // Node* helper(Node* head, unordered_map<Node*, Node*>& map) {

    //     if (head == NULL)
    //         return NULL;

    //     Node* newHead = new Node(head->val);
    //     map[head] = newHead;
    //     newHead->next = helper(head->next, map);

    //     if (head->random != NULL) {
    //         newHead->random = map[head->random];
    //     }
    //     return newHead;
    // }
    // Node* copyRandomList(Node*& head) {
    //     unordered_map<Node*, Node*>
    //         map; //  connecting old LL elements to new LL elements
    //     return helper(head, map);
    // }

    // Approach 1: TC = O(n)
    //  SC = O(1)

    Node* copyRandomList(Node*& head) {
        if (head == NULL)
            return NULL;

        // Step1: clone A -> A'
        // copying LL to make 7->7->13->13 ... ->NULL

        Node* it = head; // iterate over old LL
        while (it != NULL) {
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }

        // Step2:Assign random links of A'(new LL) with the helper of A(old LL)
        it = head;
        while (it != NULL) {
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : NULL;
            it = it->next->next;
        }

        // Step3: detach A' from A
        it = head;
        Node* clonedHead = it->next;
        while (it != NULL) {
            Node* clonedNode = it->next;
            it->next = it->next->next;
            if (clonedNode->next != NULL) {
                clonedNode->next = clonedNode->next->next;
            }
            it = it->next;
        }

        return clonedHead;
    }
};