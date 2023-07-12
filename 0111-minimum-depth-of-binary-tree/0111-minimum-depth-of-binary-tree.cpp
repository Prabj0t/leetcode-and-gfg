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
    int minDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int mindepth = 0;
        while(!q.empty())
        {
             mindepth++;
            int n = q.size();
            for(int i = 0 ; i < n; i++){
                TreeNode* a = q.front();
                
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                q.pop();
                
                if(a->left == NULL && a->right == NULL){
                    return mindepth;
                }
                
                
                
            }
           
        }
        
        return -1;
    }
};