//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
// class Solution
// {
//     public:
//     int sum( Node* root){
//         if ( root == NULL){
//             return 0 ;
//         }
//         int ans ;
//         int left = sum( root->left);
//         int right = sum( root->right);
//         if(root -> right == NULL && root ->left == NULL)
//         {
//              ans = root->data;
//         }
//         else {
//             if(root->data == left + right){
//                 ans = root->data + left + right;
//             }
//             else {
//                 ans = -1;
//             }
//         }
        
//         return ans;
//     }
//     bool isSumTree(Node* root)
//     {
//          // Your code here
//         if( root == NULL){
//             return 1;
//         }
//         if( root -> right == NULL && root ->left == NULL ){
//             return 1;
//         }
        
//         int left = sum(root->left );
//         if(left == -1){
//             return 0;
//         }
//         int right = sum(root->right);
        
        
//         if(root->data == left+right){
//             return 1;
//         }
//         else
//             return 0;
//     }
// };

class Solution
{
    public:
    
    pair<bool,int> fans(Node * root){
        if(root == NULL ){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        if( root -> right == NULL && root ->left == NULL ){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        pair<bool,int> left = fans(root->left);
        pair<bool,int> right = fans(root->right);
        
        bool leftans = left.first;
        bool rightans = right.first;
        
        bool check = root->data == left.second + right.second;
        
        pair<bool,int> ans;
        
        if ( leftans && rightans && check ){
            ans.first = true;
            ans.second = root->data + left.second + right .second;
        }
        return ans;
        
    }
    bool isSumTree(Node* root){
        return fans(root).first;
    }
};


//{ Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}
// } Driver Code Ends