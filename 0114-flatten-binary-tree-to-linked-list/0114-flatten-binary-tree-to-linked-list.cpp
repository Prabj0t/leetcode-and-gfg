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
        void preorderFlatten(TreeNode*& root, TreeNode*& prev) {
        if (root == NULL) {
            return;
        }

        // Store the left and right children of the current root
        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;

        // Modify the previous node's pointers to flatten the tree
        prev->left = nullptr;
        prev->right = root;
        prev = prev->right;

        // Recursively flatten the left and right subtrees
        preorderFlatten(leftChild, prev);
        preorderFlatten(rightChild, prev);
    }

    void flatten(TreeNode*& root) {
        if (root == NULL) {
            return;
        }

        // Create a dummy node to serve as the previous node during flattening
        TreeNode* dummyNode = new TreeNode(-1);
        TreeNode* prev = dummyNode;

        // Flatten the tree using preorder traversal
        preorderFlatten(root, prev);

        // Update the root pointer to the flattened tree
        root = dummyNode->right;

        // Clean up the dummy node to avoid memory leaks
        delete dummyNode;
    }

};