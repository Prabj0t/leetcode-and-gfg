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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;

    // Using a map to store the nodes according to their horizontal distance and level
    // map<Horizontal Distance, map<Level, Multiset of Nodes>>
    map<int, map<int, multiset<int>>> mp;

    queue<pair<TreeNode*, pair<int, int>>> q;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty()) {
        pair<TreeNode*, pair<int, int>> temp = q.front();
        q.pop();

        int lvl = temp.second.first;
        int hd = temp.second.second;

        // Insert the node's value into the multiset corresponding to its horizontal distance and level
        mp[hd][lvl].insert(temp.first->val);

        if (temp.first->left) {
            q.push(make_pair(temp.first->left, make_pair(lvl + 1, hd - 1)));
        }

        if (temp.first->right) {
            q.push(make_pair(temp.first->right, make_pair(lvl + 1, hd + 1)));
        }
    }

    for (auto i : mp) {
        vector<int> levelNodes;
        for (auto j : i.second) {
            // Insert the sorted values from the multiset into the levelNodes vector
            levelNodes.insert(levelNodes.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(levelNodes);
    }

    return ans;
}

};