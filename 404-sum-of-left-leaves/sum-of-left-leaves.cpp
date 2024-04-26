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
    int sumOfLeftLeavesHelper(TreeNode* root, bool isLeft){
        if(!root) return 0;
        if(!root->left && !root->right){
            //if the current node is left one than we will return node value else we will return 0
            if(isLeft) return root->val;
            else return 0; 
         }
        int sum = 0;
        if(root->left){
           sum += sumOfLeftLeavesHelper(root->left, true);
        }
        sum += sumOfLeftLeavesHelper(root->right, false);

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return  sumOfLeftLeavesHelper(root, false);
    }
};