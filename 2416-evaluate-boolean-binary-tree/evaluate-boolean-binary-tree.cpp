class Solution {
public:
   
    bool evaluateTree(TreeNode* root) {
        // If the root does not have a left child, it must be a leaf node (value 0 or 1)
        if (!root->left) {
            return root->val; // Return the value of the leaf node as the result
        }
        // Recursively evaluate the left subtree
        bool leftResult = evaluateTree(root->left);
        // Recursively evaluate the right subtree
        bool rightResult = evaluateTree(root->right);
        // If the root's value is 2, we perform an OR operation; otherwise, we perform an AND operation
        return root->val == 2 ? (leftResult || rightResult) : (leftResult && rightResult);
    }
};