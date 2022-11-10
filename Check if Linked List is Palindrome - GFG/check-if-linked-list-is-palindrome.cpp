//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    void insertathead(Node *&head, int key)
{
    // new node created
    Node *temp = new Node(key);
    temp->next = head;
    head = temp;
}

    bool isPalindrome(Node *head)
    {
        //Your code here
        Node * curr = head;
        Node * H2 = new Node(curr->data);
        while(curr->next != NULL){
            curr = curr -> next;
            insertathead(H2 ,curr->data);
        }
        Node * t1 = head;
        Node * t2 = H2;
        while( t1 != NULL && t2 != NULL){
            if ( t1 -> data == t2 -> data ){
                t1 = t1 -> next ;
                t2 = t2 -> next ;
            }    
            else{
                return 0 ;
            }
        }
        return 1;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends