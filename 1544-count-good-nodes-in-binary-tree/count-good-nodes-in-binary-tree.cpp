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
    void goodNodesCount(TreeNode* node, int &count, int maxVal){
        if (!node) return;

        // Check if the current node is a good node
        if (node->val >= maxVal) {
            count++;
            maxVal = node->val;  // Update maxVal to current node's value
        }

        // Traverse left and right children
        goodNodesCount(node->left, count, maxVal);
        goodNodesCount(node->right, count, maxVal);
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int count = 0;
        goodNodesCount(root, count, root->val);
        return count;
    }
};