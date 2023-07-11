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
    
    pair<int,bool> height ( TreeNode* root){
        if( root == NULL){
            pair<int,bool> p = make_pair(0, true);
            return p;
        }
        
        
        pair<int,bool> lefth = height(root->left);
        pair<int,bool> righth = height( root-> right);
        
        pair<int,bool> ans;
        ans.first = max(lefth.first , righth.first) + 1; 
        if( abs(lefth.first - righth.first) > 1 || !lefth.second || !righth.second){
            ans.second = false;
        }
        else{
            ans.second = true;
        }
        
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
        return height(root).second;
    }
};