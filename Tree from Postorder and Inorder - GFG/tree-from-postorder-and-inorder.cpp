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

Node* solve(int in[], int post[], int n, int& postIndex, int inorderStart, int inorderEnd, unordered_map<int,int> &mp) {
    // Base case: If postIndex is less than 0 or inorderStart is greater than inorderEnd, return nullptr
    if (postIndex < 0 || inorderStart > inorderEnd) {
        return nullptr;
    }

    // Current element is the last element in the postorder traversal
    int element = post[postIndex--];
    Node* root = new Node(element);

    // Find the position of the current element in the inorder array
    // int position = -1;
    // for (int i = inorderStart; i <= inorderEnd; i++) {
    //     if (in[i] == element) {
    //         position = i;
    //         break;
    //     }
    // }
    
    int position = mp[element];

    // Recursively construct the right subtree (since the right child comes before the left child in postorder)
    root->right = solve(in, post, n, postIndex, position + 1, inorderEnd, mp);
    
    // Recursively construct the left subtree (since the left child comes after the right child in postorder)
    root->left = solve(in, post, n, postIndex, inorderStart, position - 1, mp);

    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Initialize the postIndex to the last index of post array
    int postIndex = n - 1;
    unordered_map<int,int> mp;
    
    for(int i = 0 ; i < n ; i++){
        mp[in[i]] = i;
    }
    // Call the recursive function to build the binary tree
    Node* root = solve(in, post, n, postIndex, 0, n - 1 ,mp);

    return root;
}

