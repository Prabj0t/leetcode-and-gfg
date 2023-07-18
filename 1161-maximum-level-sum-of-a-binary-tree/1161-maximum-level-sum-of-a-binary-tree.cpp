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
    int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int maxSum = INT_MIN;
    int level = 0;
    int ans;

    while (!q.empty()) {
        level++;
        int sum = 0;
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* current = q.front();
            q.pop();

            sum += current->val;

            // Enqueue the left child if it exists
            if (current->left) {
                q.push(current->left);
            }

            // Enqueue the right child if it exists
            if (current->right) {
                q.push(current->right);
            }
        }

        // Update the maximum sum and the corresponding level if a higher sum is found
        if (maxSum < sum) {
            maxSum = sum;
            ans = level;
        }
    }

    // Return the level with the maximum sum
    return ans;
}

};