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
    void dfs(TreeNode* root , vector<int> &v){
        
        if(root == NULL){
            return;
        }
        if(root ->left == NULL && root->right == NULL){
            v.push_back(root->val);
            return;
        }
        
        dfs(root->left , v);
        dfs(root->right , v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        
        vector<int> v1;
        dfs(root1 , v1);
        
        vector<int> v2;
        dfs(root2 , v2);
        
        int i = 0 , j = 0;
        if(v1.size() != v2.size()){
            return false;
        }
        while(i < v1.size() , j < v2.size()){
            if(v1[i] != v2[j]){
                return false;
            }
            i++;
            j++;
        }
        return 1;
    }
};