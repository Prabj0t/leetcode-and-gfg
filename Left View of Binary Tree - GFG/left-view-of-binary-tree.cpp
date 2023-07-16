//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root) {
    vector<int> ans;

    // Check if the tree is empty
    if (root == NULL) {
        return ans;
    }

    queue<pair<Node*, int>> q; // Queue to perform BFS
    map<int, pair<int, bool>> mp; // Map to store leftmost node at each level
    q.push(make_pair(root, 0)); // Push root node with level 0 to the queue

    // Perform level order traversal
    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* cur = temp.first; // Current node
        int lvl = temp.second; // Level of the current node

        if (!mp[lvl].second) {
            mp[lvl].first = temp.first->data; // Store the leftmost node at each level
            mp[lvl].second = true; // Mark the level as visited
        }

        if (temp.first->left) {
            q.push(make_pair(temp.first->left, lvl + 1)); // Push left child with increased level
        }

        if (temp.first->right) {
            q.push(make_pair(temp.first->right, lvl + 1)); // Push right child with increased level
        }
    }

    // Traverse the map and add leftmost nodes to the result vector
    for (auto i : mp) {
        ans.push_back(i.second.first);
    }

    return ans;
}
