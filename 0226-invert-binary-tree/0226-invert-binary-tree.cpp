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
    void dfs(TreeNode* root , TreeNode* &nNode){
        if( root == NULL){
            return;
        }
        
        TreeNode* newnode = new TreeNode(root->val);
        nNode = newnode;
        
        dfs(root->left, nNode->right);
        dfs(root->right, nNode->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* nNode = new TreeNode(NULL);
        if( root == NULL){
            return root;
        }
        
        dfs(root , nNode);
        
        return nNode;
    }
};