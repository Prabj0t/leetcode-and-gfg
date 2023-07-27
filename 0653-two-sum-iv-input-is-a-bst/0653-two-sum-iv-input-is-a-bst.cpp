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
    unordered_set<int> s;

    // Function to check whether there exist two distinct nodes in a BST that have a sum equal to 'k'.
    // 'root' is the root of the BST and 'k' is the target sum.
    bool findTarget(TreeNode* root, int k) {
        // If the current node is null, return false as there are no nodes to consider.
        if (!root) {
            return false;
        }

        // Check if 'k - root->val' is already present in the unordered_set 's'.
        // If yes, it means there exists a pair of nodes with values 'root->val' and 'k - root->val' that sum up to 'k'.
        if (s.count(k - root->val)) {
            return true;
        }

        // If 'k - root->val' is not found in the unordered_set, insert 'root->val' into it.
        s.insert(root->val);

        // Recursively check for the existence of a pair in the left and right subtrees.
        // If any of the subtrees have such a pair, the function returns true.
        // Otherwise, it returns false.
        return findTarget(root->left, k) || findTarget(root->right, k);
    }

};