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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        queue<TreeNode*> q;
        
        q.push(root);
        bool LtoR = true;
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> ans(n, -1);
            for(int i = 0 ; i < n; i++){
                
                TreeNode* a = q.front();
                q.pop();
                
                int index;
                if( LtoR ){
                    index = i;
                    
                }else{
                    index = n-i-1;
                }   
                ans[index] = a->val;
                
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right); 
                
            }
//             change direction 
            LtoR = !(LtoR);
            result.push_back(ans);
            ans.clear();
           
        }
        return result;
    }
};