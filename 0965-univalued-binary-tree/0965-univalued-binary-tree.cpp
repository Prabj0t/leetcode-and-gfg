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
    bool dfs(TreeNode* root, int key){
        if(root == NULL){
            return true;
        }
        if(root->val != key){
            return false;
        }
        if(dfs(root->left ,  key) == false){
            return false;
        }
        if(dfs(root->right,  key) == false){
            return false ;  
        }
        
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        
        int key = root->val;
        return dfs(root, key );
    }
};