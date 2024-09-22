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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;

        queue<pair<TreeNode*, int>>q;
        map<int,vector<int>>mp;
        q.push({root,0});
        mp[0].push_back(root->val);

        while(!q.empty()){
            auto pair = q.front();
            q.pop();
            TreeNode* curr = pair.first;
            int level = pair.second;

            if(curr->left){
                q.push({curr->left, level+1});
                mp[level+1].push_back(curr->left->val);
            }
            if(curr->right){
                q.push({curr->right, level+1});
                mp[level+1].push_back(curr->right->val);
            }
        }

        for(const auto& m : mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};