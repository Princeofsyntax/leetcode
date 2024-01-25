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
    int ans = 0;
    void pathfromOneRoot(TreeNode* root, long long sum){
         if(!root) return;
         //follow preOrder traversal
         //base case
         if(sum == root->val) //here sum value will be changing due to recursion
         {
           ++ans;
         }
         pathfromOneRoot(root->left, sum-root->val);
         pathfromOneRoot(root->right, sum-root->val);

    }
    int pathSum(TreeNode* root, long long targetSum) 
    {
        //as we have to check from each node
       if(root){
           pathfromOneRoot(root,targetSum);
           pathSum(root->left, targetSum);
           pathSum(root->right, targetSum);
       }
       return ans;
    }
};