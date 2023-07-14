//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<pair<Node*, pair<int, int>>> q;

        map<int, pair<int, bool>> mp;
        q.push(make_pair(root, make_pair(0, 0)));


    // Perform level order traversal
        while (!q.empty()) {
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();
    
            Node* cur = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
    
            // Store the current node's data in the map using its horizontal distance and level
            if(mp[hd].second != true){
                mp[hd].first = temp.first->data;
                mp[hd].second = true;
            }
    
            // Enqueue the left child with updated horizontal distance and increased level
            if (temp.first->left) {
                q.push(make_pair(temp.first->left, make_pair(hd - 1, lvl + 1)));
            }
    
            // Enqueue the right child with updated horizontal distance and increased level
            if (temp.first->right) {
                q.push(make_pair(temp.first->right, make_pair(hd + 1, lvl + 1)));
            }
        }

    // Traverse the map to retrieve the nodes in vertical order
    for (auto i : mp) {
            ans.push_back(i.second.first);
        }
    return ans;
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends