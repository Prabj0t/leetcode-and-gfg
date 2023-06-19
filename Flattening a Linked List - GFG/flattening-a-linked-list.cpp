//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
    
Node* merge ( Node * h1 , Node * h2){
    Node* t = new Node(-1);
    Node* res = t;
    
    while( h1 != NULL && h2 != NULL ){
        if(h1 -> data < h2 -> data){
            t-> bottom = h1;
            h1 = h1 -> bottom;
        }
        else{
            t-> bottom = h2;
            h2 = h2 -> bottom;
        }
        t = t -> bottom;
    }
    if(h1 == NULL){
        t -> bottom  = h2;
    }
    else if( h2 == NULL){
        t -> bottom = h1;
    }
    
    return res-> bottom;
}

Node *flatten(Node *root)
{
    if(root -> next == NULL ){
        return root;
    }
    
    Node* t1 = flatten( root -> next);
    // cout << " t1 = " << t1 -> data << " root val = "<< root -> data<< endl;
    Node* merged = merge(t1 , root);
    
    
    // cout << "merged value" <<  merged-> data << endl;
    // merged -> next = NULL;
    return merged;
}







































// Node *flatten(Node *root)
// {
//     if (root == NULL) {
//         return NULL;
//     }
    
//     Node* cur = root;
//     Node* down = root;
//     Node* nxt = root;
    
//     while( nxt -> next != NULL )
//     {
//         while(down -> bottom != NULL) {
//             if(down -> bottom -> data < nxt -> next -> data){
//                 down = down -> bottom;
//                 cur -> next = down;
//                 cur = cur -> next;
//             }
//             else{
//                 break;
//             }
//         }
//         if(down -> bottom == NULL){
//             nxt = nxt -> next;
//             cur -> next = nxt;
//             cur = cur -> next;
//             down = nxt;
//         }
//         else if(down -> bottom -> data > nxt -> next -> data){
            
//             nxt = nxt -> next;
//             cur -> next = nxt;
//             cur = cur -> next;
            
//             while( down -> bottom != NULL){
//                 if( down -> bottom -> data < nxt -> bottom -> data ){
//                     down = down -> bottom ;
//                     cur -> next = down;
//                     cur = cur -> next;
//                 }
//                 else{
//                     Node* temp = nxt;
//                     while( temp -> bottom != NULL){
//                         temp = temp -> bottom ;
//                     }
//                     temp -> bottom = down -> bottom;
//                     down = cur;
//                     break;
//                 }
//             }
//         }
//     }
//     return root;
// }


