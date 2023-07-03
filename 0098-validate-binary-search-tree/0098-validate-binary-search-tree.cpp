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
    
//     <-------using recursion -------->
    bool check(TreeNode* root , long min , long max){
        
        if( !root  ){
            return 1;
        }
        if(root->val <= min || root->val >= max ){
            return false;
        }
            
        bool left = check ( root->left , min , root->val);
        bool right = check ( root->right , root->val , max );
        
        return left && right;

    }
    bool isValidBST(TreeNode* root ) {
        
        return check(root , LONG_MIN , LONG_MAX);
    }
    
//     bool isValidBST(TreeNode* root) {
//         return valid(root, LONG_MIN, LONG_MAX);
//     }
// private:
//     bool valid(TreeNode* root, long min, long max) {
//         if (!root) {
//             return true;
//         }
//         if (root -> val <= min || root -> val >= max) {
//             return false;
//         }
//         return valid(root -> left, min, root -> val) && valid(root -> right, root -> val, max);
//     }
    
    
    
//     <------  using inorder -------> iterative
//     void inOrder(TreeNode* root) {
//         if (!root)
//             return;
//         inOrder(root->left);
//         tree.push_back(root->val);
//         inOrder(root->right);
//     }
   
//     bool isValidBST(TreeNode* root) {
//         if (!root)
//             return true;
        
//         inOrder(root);
//         for (int i=1; i<tree.size(); i++)
//             if (tree[i] <= tree[i-1])
//                 return false;
//         return true;
//     }
// private:
//     vector<int> tree;
};