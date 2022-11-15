//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
     Node* reverse(Node * head)
    {
        Node* prev = NULL;
        Node* cur = head;
        Node * fwd = NULL ;                                      
        while ( cur != NULL)
        {
            fwd = cur -> next ;
            cur -> next = prev ;
            prev = cur ;
            cur = fwd ;
        
        }
    
    return prev;
    
    }
    void insertattail( struct Node * &head , struct Node* &tail , int data){
        Node *temp = new Node(data);
        if ( head == NULL )
        {
            head = temp;
            tail = temp;
            return;
        }
        else {
            tail-> next = temp;
            tail = temp;
        }
    }
    
    struct Node* addition( struct Node* first , struct Node* second){
        int carry = 0;
        int digit = 0;
        int sum = 0;
        Node * f1 = first ;
        Node * f2 = second;
        
        Node * anshead = NULL ;
        Node * anstail = NULL ;
        while (f1 != NULL &&  f2 != NULL ){
            sum = carry + (f1->data) + (f2->data);
            digit = sum % 10;
            carry = sum / 10;
            
            insertattail(anshead , anstail , digit );
            f1= f1-> next;
            f2 = f2-> next;
        }
        while ( f1 != NULL ){
            sum = carry + f1->data;
            digit = sum % 10;
            carry = sum / 10;
            insertattail(anshead , anstail , digit );
            f1= f1-> next;
        }
        
        while ( f2 != NULL ){
            sum = carry + f2->data;
            digit = sum % 10;
            carry = sum / 10;
            insertattail(anshead , anstail , digit );
            f2= f2-> next;
        }
        while ( carry != 0){
            sum = carry;
            digit = sum % 10;
            insertattail(anshead , anstail , digit );
            carry = sum / 10;
        }
        return anshead;
    }
    struct Node* addTwoLists(struct Node* first , struct Node* second)
    {
        // code here
        first  = reverse(first);
        second = reverse(second);
       
        Node * ans = addition( first , second );
        
        ans = reverse( ans );
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends