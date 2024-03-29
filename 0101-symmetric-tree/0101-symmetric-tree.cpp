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
    
    bool rec(TreeNode* l , TreeNode* r){
        
        if( l == NULL && r == NULL ){
            return true;
        }
        else if((l == NULL && r != NULL ) || ( l != NULL && r == NULL ) ){
            return false;
        }   
        
        if(l->val != r->val){
            return false;
        }
        
        return rec(l->right , r->left) && rec(l->left , r->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        return rec(root->left , root->right);
    }
};