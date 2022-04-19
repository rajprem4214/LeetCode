// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
     
    Node *less = new Node(INT_MIN);
    Node *eqal = new Node(x);
    Node *gret = new Node(x);
    
    Node *p1  =less,*p2 = eqal,*p3 = gret;
    
    Node*temp = new Node(0);
    temp->next = head;
    while(temp->next)
    {
        if(temp->next->data<x)
        {
            p1->next = temp->next;
            temp->next = temp->next->next;
            p1=p1->next;
            p1->next = NULL;
        }
        else if(temp->next->data==x)
        {
            p2->next = temp->next;
            temp->next = temp->next->next;
            p2 = p2->next;
            p2->next = NULL;
        }
        else
        {
            p3->next = temp->next;
            temp->next = temp->next->next;
            p3 = p3->next;
            p3->next = NULL;
        }
        
    }

    p2->next = gret->next;
    p1->next = eqal->next;
    
    return less->next;
}