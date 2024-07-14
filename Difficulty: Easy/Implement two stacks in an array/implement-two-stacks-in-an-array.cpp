//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks {
  public:
    int *arr;
    int size;
    int top1;
    int top2;

    twoStacks() {
        size = 100; // Default size
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Function to push an integer into the first stack.
    void push1(int x) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = x;
        }
        // Overflow condition is handled by not allowing push if there's no space
    }

    // Function to push an integer into the second stack.
    void push2(int x) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = x;
        }
        // Overflow condition is handled by not allowing push if there's no space
    }

    // Function to remove an element from the top of the first stack.
    int pop1() {
        if (top1 == -1) {
            // Stack underflow
            return -1;
        } else {
            int popped = arr[top1];
            top1--;
            return popped;
        }
    }

    // Function to remove an element from the top of the second stack.
    int pop2() {
        if (top2 == size) {
            // Stack underflow
            return -1;
        } else {
            int popped = arr[top2];
            top2++;
            return popped;
        }
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends