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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        // q.push(NULL);
        while(!q.empty() ){
            int s = q.size();
            double sum = 0;
            for(int i = 0 ; i < s ; i++){
                TreeNode* n = q.front();
                sum += n->val;
                q.pop();
                
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                
            }
            // q.pop();
            double avg = sum/s;
            ans.push_back(avg);
            // if(q.empty()){
            //     return ans;
            // }
            // q.push(NULL);   
        }
        return ans;
    }
};