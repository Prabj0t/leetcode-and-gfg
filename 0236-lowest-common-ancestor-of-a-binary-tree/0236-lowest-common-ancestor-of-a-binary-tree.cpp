/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    // Function to find the lowest common ancestor of nodes p and q in a binary tree
//     TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (root == NULL) {
//             return NULL;
//         }

//         // If the current node is either p or q
//         if (root->val == p->val || root->val == q->val) {
//             return root;
//         }

//         // Recursively search for p and q in the left and right subtrees
//         TreeNode* left = solve(root->left, p, q);
//         TreeNode* right = solve(root->right, p, q);

//         // If both p and q are found in different subtrees, the current node is the lowest common ancestor
//         if (left != NULL && right != NULL) {
//             return root;
//         }
        
//         else if (left == NULL && right != NULL) {
//             return right;
//         }
//         else if (left != NULL && right == NULL) {
//             return left;
//         }

//         // If neither p nor q is found in the current subtree, return NULL
//         return NULL;
//     }

    
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (root == NULL) {
//             return NULL;
//         }

//         // Call the 'solve' function to find the lowest common ancestor
//         return solve(root, p, q);
//     }
    
    
    // Function to find the lowest common ancestor of nodes p and q in a binary tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case: If root is NULL or it matches either p or q, it is the lowest common ancestor
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    // Recursively search for p and q in the left and right subtrees
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    // If both p and q are found in different subtrees, the current node is the lowest common ancestor
    if (left != NULL && right != NULL) {
        return root;
    }
    // If only p is found, return p as the lowest common ancestor
    else if (left != NULL) {
        return left;
    }
    // If only q is found, return q as the lowest common ancestor
    else {
        return right;
    }
}


};