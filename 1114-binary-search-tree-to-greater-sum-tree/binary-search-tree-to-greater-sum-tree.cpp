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
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return nullptr;

        // Traverse the right subtree
        bstToGst(root->right);
        
        // Update the sum and node value
        sum += root->val;
        root->val = sum;
        
        // Traverse the left subtree
        bstToGst(root->left);
        
        return root;

    }
};