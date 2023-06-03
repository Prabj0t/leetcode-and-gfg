//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node* rev ( Node* &head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* chotahead = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return chotahead;
    }
    Node *compute(Node *head)
    {
        Node* revh = rev(head);
        Node* temp = revh;
        
        while(temp->next != NULL){
            if( temp -> next -> data < temp->data){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }
        
        Node* revagain = rev(revh);
        return revagain;
    }
};



//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends