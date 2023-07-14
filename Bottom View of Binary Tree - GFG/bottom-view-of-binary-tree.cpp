//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


vector <int> bottomView(Node *root);

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


// } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
        vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;

    // Check if the tree is empty
        if (root == NULL) {
            return ans;
        }

        queue<pair<Node*, int>> q;  // Queue to perform level order traversal

        map<int, pair<int, bool>> mp;  // Map to store nodes with their horizontal distance
    
        // Add root node to the queue with horizontal distance 0
        q.push(make_pair(root, 0));
    
        // Perform level order traversal
        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
    
            Node* cur = temp.first;
            int hd = temp.second;
    
            // Store the current node's data in the map using its horizontal distance,
            // if it's the first node encountered at that distance
            
            // rewrite the value from top to bottom
            mp[hd].first = temp.first->data;
    
            // Enqueue the left child with updated horizontal distance
            if (temp.first->left) {
                q.push(make_pair(temp.first->left, hd - 1));
            }
    
            // Enqueue the right child with updated horizontal distance
            if (temp.first->right) {
                q.push(make_pair(temp.first->right, hd + 1));
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
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends