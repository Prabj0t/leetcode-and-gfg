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
    
    int sum(TreeNode* root , int &ans ){
        
        if(root == NULL){
            return ans;
        }
        if( root ->left && root->left->left == NULL && root->left->right == NULL){
            ans+=root->left->val;
        }
        
        int lefti = sum(root->left, ans);
        int righti = sum(root->right, ans);
        
        return lefti+righti;
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sum(root , ans);
        
        return ans;
    }
};