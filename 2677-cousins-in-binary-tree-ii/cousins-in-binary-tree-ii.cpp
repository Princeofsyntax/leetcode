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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>>q;
        q.push({root,nullptr});
        while(!q.empty()){
            int n = q.size();
            unordered_map<TreeNode*,int>mp;
            for(int i= 0 ; i < n; i++){
                auto pairNode = q.front();
                q.pop();
                mp[pairNode.second] += pairNode.first->val; 
                q.push(pairNode);
            }
            for(int i = 0; i < n; i++){
                auto pairNode = q.front();
                q.pop();
                int sum = 0;
                for(auto m : mp){
                    if(m.first != pairNode.second){
                        sum += m.second;
                    }
                }
                pairNode.first->val = sum;
                if(pairNode.first->left)q.push({pairNode.first->left, pairNode.first});
                if(pairNode.first->right)q.push({pairNode.first->right, pairNode.first});
            }
        }
        return root;
    }
};