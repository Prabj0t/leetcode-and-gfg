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
    
    // Function to recursively find paths and count the number of paths that sum to the target
void solve(TreeNode* root, int targetSum, vector<int>& path, int& count) {
    if (root == NULL) {
        return;
    }

    path.push_back(root->val); // Add the current node's value to the path

    solve(root->left, targetSum, path, count); 
    solve(root->right, targetSum, path, count); 

    long long sum = 0; // to handle larger values
    for (int i = path.size() - 1; i >= 0; i--) {
        sum += path[i]; 

        if (sum == targetSum) {
            count++; 
        }
    }

    path.pop_back(); // Remove the current node's value from the path to backtrack
}

    
int pathSum(TreeNode* root, int targetSum) {
    int count = 0;
    vector<int> path; 
    solve(root, targetSum, path, count);
    return count; // Return the count
}

/* 
   Time Complexity:
   The time complexity of this solution is O(N^2), where N is the number of nodes in the binary tree. 
   The recursion traverses all the nodes in the tree, and in the worst case, the path size can be N,
   resulting in a nested loop that iterates N times.

   Space Complexity:
   The space complexity is O(N) in the worst case. This is because the recursion depth can be equal to
   the height of the tree, and in the worst case, the tree can be skewed, resulting in a height of N.
   Additionally, the path vector can store up to N nodes in the worst case, contributing to the space usage.
*/


};