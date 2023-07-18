//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
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


// } Driver Code Ends
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    void rec(Node* root, pair<int, int>& ans, pair<int, int>& temp) {
    // Base case: If the current node is NULL (leaf node reached)
    if (root == NULL) {
        // Check if the path from root to leaf is longer than the current longest path
        if (temp.second > ans.second) {
            ans.second = temp.second;
            ans.first = temp.first;
        }
        // If the path length is the same, update the maximum sum
        else if (temp.second == ans.second) {
            ans.first = max(ans.first, temp.first);
        }
        return;
    }
    
    // Add the current node's data to the running sum and increment the path length
    temp.first += root->data;
    temp.second += 1;

    // Recursively traverse the left subtree
    rec(root->left, ans, temp);

    // Recursively traverse the right subtree
    rec(root->right, ans, temp);

    // Decrement the path length and subtract the current node's data from the running sum
    temp.second -= 1;
    temp.first -= root->data;

    return;
}

int sumOfLongRootToLeafPath(Node* root) {
    // Initialize the answer and temporary variables
    pair<int, int> ans = make_pair(0, 0);
    pair<int, int> temp = make_pair(0, 0);

    // Call the recursive function
    rec(root, ans, temp);

    // Return the maximum sum of the longest root-to-leaf path
    return ans.first;
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
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends