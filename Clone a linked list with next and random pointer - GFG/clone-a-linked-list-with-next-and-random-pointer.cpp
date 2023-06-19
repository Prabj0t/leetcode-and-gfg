//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};



// } Driver Code Ends
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node * org = head;
        Node * fwd = head;
        
        // First round: make copy of each node,
          // and link them together side-by-side in a single list.
        while( org != NULL){
            
            fwd = org -> next; 
            
            Node* temp = new Node(org->data);
            org -> next = temp;
            temp -> next = fwd;
            
            org = fwd;
        }
        
        // Second round: assign random pointers for the copy nodes.
        org = head;
        while(org != NULL){
            if(org -> arb != NULL){
                org-> next -> arb = org -> arb -> next;
            }
            
            org = org -> next -> next;
        }
        
        // Third round: restore the original list, and extract the copy list.
        org = head;
        Node* clonehead = new Node(0);
        Node* temp = clonehead;
        fwd = head;
        
        while(org != NULL && temp  != NULL ){
            fwd = org -> next -> next;
            
//             retrive clone
            temp -> next = org -> next;
//             retrive orinal
            org -> next = fwd;
            
            org = fwd;
            temp = temp -> next;
                
        }
        // org -> next = NULL;
        return clonehead -> next;
    }
        
};







// class Solution
// {
// private:
//     void insertattail(Node *&head, Node *&tail, int data)
//     {
//         Node *newNode = new Node(data);
//         if (head == NULL)
//         {
//             head = newNode;
//             tail = newNode;
//             return;
//         }
//         else
//         {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

// public:
//     Node *copyRandomList(Node *head)
//     {
             
        
//         unordered_map< Node* , Node*> oldtonew ;
        
//         Node *clonehead = NULL;
//         Node *clonetail = NULL;
        
//         Node *temp2 = clonehead;
//         Node *original = head;
//         while (original != NULL)
//         {
//             insertattail(clonehead, clonetail, original->val);
//             // original = original->next;
            
//             oldtonew[original] = clonetail;
//             original = original -> next;
//         }
        
//         original = head;
//         temp2 = clonehead;
        
//         while (original != NULL)
//         {
//             if( original -> random != NULL){
//                 oldtonew[original]->random = oldtonew[original->random];
//             }
//             else{
//                 oldtonew[original]->random = NULL;
//             }
//             original = original -> next;
//         }
//         return clonehead;
//     }
// };



// optimal striver inline approach... 
/*
1. make clone and insert the nodes in the original Linked List
2. make random links of clone as the original 
3. retrive the original and cloned Linked list ( separation ) 
*/




/* love babbar optimal */

// class Solution
// {
// private:
//     void insertattail(Node *&head, Node *&tail, int data)
//     {
//         Node *newNode = new Node(data);
//         if (head == NULL)
//         {
//             head = newNode;
//             tail = newNode;
//             return;
//         }
//         else
//         {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

// public:
//     Node *copyRandomList(Node *head)
//     {

//         Node *clonehead = NULL;
//         Node *clonetail = NULL;

//         Node *original = head;
//         while (original != NULL)
//         {
//             insertattail(clonehead, clonetail, original->val);
//             original = original->next;
//         }
//         // unordered_map< Node* , Node*> oldtonew ;
//         original = head;
//         Node *temp2 = clonehead;
//         Node *fwd = original;
//         Node *fwd2 = temp2;
//         while (original != NULL && temp2 != NULL)
//         {
//             // oldtonew[original] = temp2;
//             fwd = original->next;
//             original->next = temp2;
//             original = fwd;

//             fwd2 = temp2->next;
//             temp2->next = original;
//             temp2 = fwd2;

//             // original = original -> next;
//             // temp2 = temp2 -> next;
//         }
//         original = head;
//         temp2 = clonehead;
//         while (original != NULL && temp2 != NULL)
//         {
//             if( original -> random != NULL){
//                 temp2 -> random = original -> random -> next;
//             }
//             else{
//                 temp2-> random = NULL;
//             }
//             original = temp2 -> next;
//             if( original != NULL){
//                     temp2 = original -> next;
//             }
//         }
        
//         original = head;
//         temp2 = clonehead;
//         while (temp2 != NULL && original != NULL)
//         {
//             original->next = original->next->next;
//             original = original->next;

//             if (original != NULL)
//             {
//                 temp2->next = original->next;
//             }
//             temp2 = temp2->next;
//         }
//         return clonehead;
//     }
// };

//{ Driver Code Starts.


void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}


void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {


    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}



int main() {

    int T, i, n, l, k;
    Node *generated_addr = NULL;
     /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        Solution ob;
        struct Node *res = ob.copyList(head);
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
// } Driver Code Ends