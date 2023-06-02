//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node* head) {
    Node* odd = NULL;
    Node* even = NULL;
    Node* oddTail = NULL;
    Node* evenTail = NULL;

    while (head != NULL) {
        if (head->data % 2 == 0) {
            if (even == NULL) {
                even = head;
                evenTail = head;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        } else {
            if (odd == NULL) {
                odd = head;
                oddTail = head;
            } else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }

    if (evenTail != NULL)
        evenTail->next = odd;
    if (oddTail != NULL)
        oddTail->next = NULL;

    if (even == NULL)
        return odd;
    else
        return even;
}
    // Node* divide(int N, Node *head){
    //     // code here
    //     Node* t1 = NULL;
    //     Node* odd = NULL;
    //     Node* even = NULL;
    //     Node* t2 = NULL;
    //     if( head -> data % 2 == 0){
    //         even = head;
    //         t2 = even;
    //         while(t2->next != NULL){
    //             if(t2->next->data % 2 == 0){
    //                 t2 = t2-> next;
    //             }
    //             else{
    //                 odd = t2->next;
    //                 t1 = odd;
    //                 break;
    //             }
    //         }
    //         while( t2-> next != NULL && t1->next != NULL ){
    //                 if(t1->next->data % 2 != 0){
    //                     t1 = t1-> next;
    //                 }
    //                 else{
    //                     t2->next = t1->next;
    //                     t2 = t2->next;
    //                     if(t2->next->data % 2 == 0){
    //                         t2 = t2-> next;
    //                     }
    //                     else{
    //                         t1->next = t2->next;
    //                         t1 = t1->next;
    //                     }
    //                 }
    //             }
    //             if(t1 != NULL){
    //                 t1->next = NULL;
    //                 t2->next = odd;
    //             }
    //     } 
        
        
    //     else{
    //         odd = head;
    //         t1 = odd;
    //         while(t1->next != NULL){
    //             if(t1->next->data % 2 != 0){
    //                 t1 = t1-> next;
    //             }
    //             else{
    //                 even = t1->next;
    //                 t2 = even;
    //                 break;
    //             }
    //         }
    //         while( t1->next != NULL && t2-> next != NULL ){
    //                 if(t2->next->data % 2 == 0){
    //                     t2 = t2-> next;
    //                 }
    //                 else{
    //                     t1->next = t2->next;
    //                     t1 = t1->next;
    //                     if(t1->next->data % 2 != 0){
    //                         t1 = t1-> next;
    //                     }
    //                     else{
    //                         t2->next = t1->next;
    //                         t2 = t2->next;
    //                     }
    //                 }
    //             }
    //             if(t2 != NULL){
    //                 t1->next = NULL;
    //                 t2->next = odd;
    //             }
                
    //     }
    //     if(even == NULL){
    //         return odd;
    //     }
    //     else{
    //         return even;
    //     }
    // }
};

    // void kushv(Node * head ,Node * n,Node *t2,Node *t1){
    //     while(t2->next != NULL){
    //             if(t2->next->data % 2 == 0){
    //                 t2 = t2-> next;
    //             }
    //             else{
    //                 n = t2->next;
    //                 t1 = n;
    //                 break;
    //             }
    //         }
            //  while( t2-> next != NULL && t1->next != NULL ){
            //         if(t1->next->data % 2 != 0){
            //             t1 = t1-> next;
            //         }
            //         else{
            //             t2->next = t1->next;
            //             t2 = t2->next;
            //             if(t2->next->data % 2 == 0){
            //                 t2 = t2-> next;
            //             }
            //             else{
            //                 t1->next = t2->next;
            //                 t1 = t1->next;
            //             }
            //         }
            //     }
            //     if(t1 != NULL){
            //         t1->next = NULL;
            //         t2->next = odd;
            //     }
                
    // }
    // Node* divide(int N, Node *head){
    //     // code here
    //     Node* t1 = NULL;
    //     Node* odd = NULL;
    //     Node* even = NULL;
    //     Node* t2 = NULL;
    //     if( head -> data % 2 == 0){
    //         even = head;
    //         t2 = even;
            
    //         kushv(even , odd, t2,t1);
    //         if(odd != NULL){
    //                 t1->next = NULL;
    //                 t2->next = odd;
    //         }
    //     }
    //     else{
    //         odd = head;
    //         t1 = odd;
    //         kushv(odd ,even,t1,t2);
    //         if(even != NULL){
    //             t1->next = NULL;
    //             t2->next = even;
    //         }
                
    //     }
        
    //     if(even == NULL){
    //         return odd;
    //     }
    //     else{
    //         return even;
    //     }
    // }

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends