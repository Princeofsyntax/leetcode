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
    void solve(TreeNode* root, vector<vector<int>> &ans, int currSum,vector<int> path, int targetSum){
        //base case
        if(root == NULL)
        {
            return;
        }
        //leaf node
        if(root->left == NULL && root->right == NULL)
        {
            path.push_back(root->val);
            currSum += root->val;
            if(currSum == targetSum)
            {
                ans.push_back(path);
            }
            return;
        }
        //include current node
        path.push_back(root->val);
        currSum += root->val;

        //recursion
        solve(root->left, ans, currSum, path, targetSum);
        solve(root->right, ans, currSum, path, targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> temp;
        solve(root,ans,sum,temp,targetSum);
        return ans;
    }
};