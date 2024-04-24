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
    void dfs(TreeNode* root, int path, int& ans) {
        if (root == nullptr) // Base case: If the current node is null, return
            return;
        if (root->left == nullptr && root->right == nullptr) { // If it's a leaf node
            ans += path * 10 + root->val; // Update the sum with the value of the current root-to-leaf path
            return; // Return to avoid further traversal
        }

        // Recursively traverse the left and right subtrees, updating the path sum
        dfs(root->left, path * 10 + root->val, ans);
        dfs(root->right, path * 10 + root->val, ans);
        }
    int sumNumbers(TreeNode* root) {
        int ans = 0; 
        dfs(root, 0, ans); // Call the depth-first search function to traverse the tree
        return ans; // Return the final sum
    }
};