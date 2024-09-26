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
    int helper(TreeNode* node, int &maxi){
        if(!node) return 0;
        
        int leftSum = max(0,helper(node->left, maxi));
        int rightSum = max(0,helper(node->right, maxi));
        maxi = max(maxi, (node->val + leftSum + rightSum));
        return (node->val) + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};