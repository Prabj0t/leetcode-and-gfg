//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

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
   Node* root = new Node(stoi(ip[0]));
 
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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

// In-order traversal to store node values in the vector 'inn'.
void inorder(struct Node* root, vector<float> &inn) {
    if (root == NULL) {
        return; // Base case: Return when reaching the end of the tree.
    }

    inorder(root->left, inn); // Traverse left subtree.
    inn.push_back(root->data); // Store the current node value in 'inn'.
    inorder(root->right, inn); // Traverse right subtree.
    return; // End of the function.
}

// Function to find the median of the values in the binary search tree.
float findMedian(struct Node *root) {
    //Code here
    float ans; // Variable to store the median.
    vector<float> inn; // Vector to store node values in sorted order.
    inorder(root, inn); // Perform in-order traversal to populate 'inn' with node values.
    int n = inn.size(); // Get the size of the vector.

    if (n % 2 == 0) {
        // If the number of elements is even, take the average of the two middle elements.
        ans = (inn[n / 2] + inn[n / 2 - 1]) / 2;
    } else {
        // If the number of elements is odd, take the middle element as the median.
        ans = inn[n / 2];
    }

    return ans; // Return the calculated median.
}


