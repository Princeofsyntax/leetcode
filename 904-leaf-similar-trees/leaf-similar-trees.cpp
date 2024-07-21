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
    vector<int>ans1;
    vector<int>ans2;

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        helper(root1, ans1);
        helper(root2, ans2);

        return ans1 == ans2;
    }

private:
    void helper(TreeNode* node, vector<int>&ans){
        if(!node) return;
        if(!node->left && !node->right){
            ans.push_back(node->val);
        }
        helper(node->left, ans);
        helper(node->right, ans);
    }
};