/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void createMapping(vector<int>& inorder, map<int, int> &nodeToindex, int n ){
        for (int i = 0; i < n; i++) {
            nodeToindex[inorder[i]] = i;
        }
    }
    
        TreeNode* solve(vector<int>& preorder, vector<int>& inorder, map<int, int> &nodeToindex, int n, int &index, int inorderStart, int inorderEnd) {
        
        // Base case: If index is out of range or inorderStart is greater than inorderEnd, return nullptr
        if (index >= n || inorderStart > inorderEnd) {
            return nullptr;
        }
        
        int element = preorder[index++];
        // Create a new node with the current preorder element
        TreeNode* root = new TreeNode(element);

        // Find the position of the current preorder element in the inorder array
        int position = nodeToindex[element] ;
        
        // index++; // Increment index to get the next element in the preorder array

        // Recur for the left and right subtrees
        root->left = solve(preorder, inorder  , nodeToindex, n, index, inorderStart, position-1);
        root->right = solve(preorder, inorder  , nodeToindex, n, index, position+1, inorderEnd);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preIndex = 0; 
        map<int,int> nodeToindex;
        
        
        int n = inorder.size();
        createMapping(inorder , nodeToindex, n);
        
        // Call the recursive function to build the binary tree
        TreeNode* root = solve(preorder, inorder  , nodeToindex, n, preIndex, 0, n - 1);
        return root;
    
    }
};