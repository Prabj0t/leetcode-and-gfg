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
    bool ans = true;
    void dfs(TreeNode* root, int key){
        if(root == NULL){
            return;
        }
        if(root->val != key){
            ans = false;
            return;
        }
        dfs(root->left ,  key);
        dfs(root->right,  key);
        
        return ;
    }
    bool isUnivalTree(TreeNode* root) {
        
        int key = root->val;
        
        dfs(root, key );
        return ans;
    }
};