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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int maxsum = INT_MIN;
        int level = 0;
        int ans ;
        
        while(!q.empty()){
            level++;
            int sum = 0 ;
            int size = q.size();
            
            for(int i = 0 ; i < size ;i++){
                TreeNode* topi = q.front();
                q.pop();
                
                sum+= topi->val;
                
                if(topi->left){
                    q.push(topi->left);
                }
                if(topi->right){
                    q.push(topi->right);
                }
            }
                        
            if(maxsum < sum){
                maxsum = sum;
                ans = level;
                
                cout << ans<< endl;
            }
        }
        return ans;
    }
};