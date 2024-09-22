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
         if (!root) return {};
         vector<vector<int>> result;
         queue<pair<TreeNode*, pair<int, int>>> q;

        map<int, map<int, multiset<int>>> mp;
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* curr = p.first;
            int vertical = p.second.first;
            int level = p.second.second;
            
            mp[vertical][level].insert(curr->val);
            
            if (curr->left) {
                q.push({curr->left, {vertical - 1, level + 1}});
            }
            if (curr->right) {
                q.push({curr->right, {vertical + 1, level + 1}});
            }
        }
        
        for (auto& [vertical, nodes_at_levels] : mp) {
            vector<int> col;
            for (auto& [level, nodes] : nodes_at_levels) {
                col.insert(col.end(), nodes.begin(), nodes.end());
            }
            result.push_back(col);
        }
        
        return result;
    }
};