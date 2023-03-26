//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

    // void creatmap(int in[] , map<int, int > &mapp , int n ){
    //     for( int i = 0 ; i < n ; i++){
    //         // store index of every element on the index=element in mapp 
    //         mapp[in[i]] = i;
    //     }
    // }
    
Node* Solve(int in[] , int post[],  int instart , int inend, int &index  , map<int,int> &mapp ,int n ){
    // base case 
    if(index < 0 || instart > inend ){
    return NULL;
        
    }
    // start from first element of preorder which is our root according NLR rule
    int element = post[index--];
    Node* root = new Node(element);
    int position = mapp[element];
    // reccirsive calls 
        
    root->right = Solve(in , post,  position + 1 ,inend , index , mapp, n);
    root->left = Solve(in , post , instart , position - 1 , index , mapp, n);
    return root;
}
Node* buildTree(int in[],int post[], int n)
{
    map<int,int> nodetoindex;
    // creat Nodes to index mapping
    // creatmap(in , nodetoindex , n);
    for(int i = 0 ; i < n ; i++){
        // store index of every element on the index=element in mapp 
       nodetoindex[in[i]] = i;
    }
    int postorderIndex = n-1;
    Node* ans = Solve(in , post  , 0 , n-1,  postorderIndex ,nodetoindex, n);
    return ans;
        // Code here
}
// Node *buildTree(int in[], int post[], int n) {
//     // Your code here
// }
