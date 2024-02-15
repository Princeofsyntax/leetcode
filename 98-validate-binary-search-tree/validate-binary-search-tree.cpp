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
    bool solve(TreeNode* root, long long int lb, long long int ub){
        //base case
        if(!root){
            return true; //as absence of  node can be taken as BST (as nothhing is present there)
        }
        if(root->val > lb && root->val < ub){
            bool leftAns = solve(root->left, lb, root->val); //upperBound is updated
            bool rightAns = solve(root->right, root->val,ub); //lowerBound is updated

            return leftAns && rightAns; //as both need to be true to get finallly true
        }
        else{
            return false; //not in range
        }
    }
   
    bool isValidBST(TreeNode* root) {
        long long int lowerBound = -4294967296; //as i/p can be MORE THAN INT_MIN/MAX
        long long int upperBound = 4294967296;
        bool ans = solve(root, lowerBound, upperBound);
        return ans;
    }
};