//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head == NULL){
            cout<<"LL is empty"<<endl;
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        
        //create dummy nodes
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        //traverse the original LL
        Node* curr = head;
        while(curr!=NULL){
            if(curr->data == 0 ){
                //remove zero from original LL
                Node* temp = curr;
                curr = curr->next;
                temp->next = NULL;
                
                //append zero into new 'zeroHead' wali LL
                zeroTail->next = temp;
                zeroTail = temp;
            }
            else if(curr->data == 1 ){
                //remove one from original LL
                Node* temp = curr;
                curr = curr->next;
                temp->next = NULL;
                
                //append one into new 'oneHead' wali LL
                oneTail->next = temp;
                oneTail = temp;
            }
            else if(curr->data == 2 ){
                //remove two from original LL
                Node* temp = curr;
                curr = curr->next;
                temp->next = NULL;
                
                //append two into new 'twoHead' wali LL
                twoTail->next = temp;
                twoTail = temp;
            }
        }
        
        //now zeroHead, oneHead and twoHead LL's are all ready
        //to join them delete dummy nodes
        
        //modify oneHead LL
        Node* temp = oneHead;
        oneHead = oneHead->next;
        temp->next = NULL;
        delete temp;
        
        //modify twoHead LL
        temp = twoHead;
        twoHead = twoHead->next;
        temp->next = NULL;
        delete temp;
        
        //join the lists
        if(oneHead != NULL){
            zeroTail->next = oneHead;
            if(twoHead!=NULL){
                oneTail->next = twoHead;
            }
        }
        else{
            //oneHead is empty
            if(twoHead!= NULL){
            zeroTail->next = twoHead;
            }
        }
        
        //remove zeroHead ka dummy node
        temp = zeroHead;
        zeroHead = zeroHead->next;
        temp->next = NULL;
        delete temp;
        
        //return head of overall LL
        return zeroHead;
    }
};











//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends