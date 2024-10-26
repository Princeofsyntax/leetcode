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
    unordered_map<int, int> valToHeight;    
    unordered_map<int, int> valToMaxHeight;  

    int computeHeight(TreeNode* node) {
        if (!node) return 0;
        
        if (valToHeight.find(node->val) != valToHeight.end())
            return valToHeight[node->val];
        
        int leftHeight = computeHeight(node->left);
        int rightHeight = computeHeight(node->right);
        valToHeight[node->val] = 1 + max(leftHeight, rightHeight);
        
        return valToHeight[node->val];
    }

    void calculateMaxHeightWithoutSubtree(TreeNode* node, int depth, int maxHeightWithout) {
        if (!node) return;

        valToMaxHeight[node->val] = maxHeightWithout;

        calculateMaxHeightWithoutSubtree(node->left, depth + 1, max(maxHeightWithout, depth + computeHeight(node->right)));
        calculateMaxHeightWithoutSubtree(node->right, depth + 1, max(maxHeightWithout, depth + computeHeight(node->left)));
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> result;
        computeHeight(root);
        calculateMaxHeightWithoutSubtree(root, 0, 0);

        for (const int query : queries)
            result.push_back(valToMaxHeight[query]);

        return result;
    }
};