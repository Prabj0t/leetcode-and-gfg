//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node *Inorder(Node *root)
{
    if (root->left == NULL)
        return root;
    Inorder(root->left);
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution
{
public:
    bool flag = true;
    void inorder(Node* root , Node* &prev , Node* &newroot){
        
        if(root == NULL){
            return;
        }
        
        inorder(root->left , prev , newroot);
        if(flag == true){
            newroot = root;
            flag = false;
        }
        
        if (prev != nullptr) {
            prev->next = root;
        }
        prev = root;
        inorder(root->right , prev, newroot);
        
    }
    void populateNext(Node *root)
    {
        //code here
        if(root == NULL){
            return;
        }
        Node* prev = NULL;
        Node* newroot = NULL;
        inorder(root , prev , newroot);
        
        // this two should not be null because then how the tree traverse and print answer
        // prev ->left = NULL ;
        // prev ->right = NULL ;
        prev ->next = NULL ;
        // if (prev != nullptr) {
        //     prev->next = nullptr;
        // }
        root = newroot;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        obj.populateNext(root);
        Node *ptr = Inorder(root);
        while (ptr)
        {
            printf("%d->%d ", ptr->data, ptr->next ? ptr->next->data : -1);
            ptr = ptr->next;
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends