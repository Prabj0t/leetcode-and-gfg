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

class Solution
{
public:
    // void toindex(vector<int>& inorder , int n , map<int,int> &mapp){
    //     for(int i = 0 ; i < n ; i++){
    //         mapp[inorder[i]] = i ;
    //     };
    // }
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, map<int, int> &mapp, int n, int &index, int instart, int inend)
    {
        if (index < 0 || instart > inend)
        {
            return NULL;
        }
        int element = postorder[index--];
        // if(element == INT_MIN){
        //     return NULL;
        // }
        TreeNode *root = new TreeNode(element);

        int position = mapp[element];

        root->right = solve(inorder, postorder, mapp, n, index, position + 1, inend);
        root->left = solve(inorder, postorder, mapp, n, index, instart, position - 1);
        // if (position < instart || position > inend)
        // {
        //    return NULL;
        // }
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int size = inorder.size();
        map<int, int> mapp;
        for (int i = 0; i < size; i++)
        {
            mapp[inorder[i]] = i;
        }
        int postindex = size - 1;
        // toindex(inorder , size ,mapp);
        TreeNode *ans = solve(inorder, postorder, mapp, size, postindex, 0, size - 1);
        return ans;
    }
};