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

class NodeValue {
public: 
    int minNode;
    int maxNode;
    int sum;
    bool isBST;

    NodeValue(int minNode, int maxNode, int sum, bool isBST) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
        this->isBST = isBST;
    }
};

class Solution {
public:
    int maxSum = 0;

    NodeValue largestBSTSum(TreeNode* root) {
       if (!root) return NodeValue(INT_MAX, INT_MIN, 0, true);

        NodeValue left = largestBSTSum(root->left);
        NodeValue right = largestBSTSum(root->right);

        if (left.isBST && right.isBST && root->val > left.maxNode && root->val < right.minNode) {
            int currentSum = left.sum + right.sum + root->val;
            
           maxSum = max(maxSum, currentSum);

            return NodeValue(min(left.minNode, root->val), max(right.maxNode, root->val), currentSum, true);
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.sum, right.sum), false);
    }

    int maxSumBST(TreeNode* root) {
        largestBSTSum(root);
        return maxSum;
    }
};