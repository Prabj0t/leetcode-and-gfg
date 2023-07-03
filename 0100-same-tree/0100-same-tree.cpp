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
    
    bool check(TreeNode* p, TreeNode* q){        
        
        if( p == NULL && q == NULL){
            return p == q;
        }
        if(p == NULL || q == NULL){
            return 0;
        }
        if(p->val != q->val){
            return 0;
        }
        
        bool left = check(p->left, q->left);
        bool right = check(p->right, q->right);
        
        return (left && right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode* h1 = p;
        TreeNode* h2 = q;
        return check(p , q);
    }
};