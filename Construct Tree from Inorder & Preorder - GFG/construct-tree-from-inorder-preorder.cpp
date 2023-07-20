//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution {
public:

    // void createMapping(int in[], int n, map<int, int>& nodeToindex) {
    //     for (int i = 0; i < n; i++) {
    //         nodeToindex[in[i]] = i;
    //     }
    // }
    
    Node* solve(int in[], int pre[], int n, int& preIndex, int inorderStart, int inorderEnd) {
    if (preIndex >= n || inorderStart > inorderEnd) {
        return nullptr;
    }

    int element = pre[preIndex++];
    Node* root = new Node(element);
    // root->data = element;
    // root->left = root->right = nullptr;

    int position = -1;
    for (int i = inorderStart; i <= inorderEnd; i++) {
        if (in[i] == element) {
            position = i;
            break;
        }
    }

    root->left = solve(in, pre, n, preIndex, inorderStart, position - 1);
    root->right = solve(in, pre, n, preIndex, position + 1, inorderEnd);

    return root;
}
    
    Node* buildTree(int in[], int pre[], int n) {
        int preIndex = 0;
        
    
        Node* root = solve(in, pre, n, preIndex, 0, n - 1);


        return root;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends