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
    
        int sum(TreeNode* root, int& ans) {
        // If the root is NULL, return the current value of 'ans'
            if (root == NULL) {
                return ans;
            }

        // Check if the left child exists and is a leaf node
            if (root->left && root->left->left == NULL && root->left->right == NULL) {
                ans += root->left->val; // Add the value of the left leaf node to 'ans'
            }

        // Recursively calculate the sum of left leaves in the left and right subtrees
            int leftSum = sum(root->left, ans);
            int rightSum = sum(root->right, ans);

            return leftSum + rightSum; // Return the sum of left leaves
        }

        int sumOfLeftLeaves(TreeNode* root) {
            int ans = 0;
            sum(root, ans); // Call the helper function to calculate the sum of left leaves

            return ans; // Return the final sum
        }

};