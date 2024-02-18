/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        //base case
        if(root==NULL){
            return NULL;
        }
        if(p->val < root->val && q->val < root->val){
            //left answer
            return lowestCommonAncestor(root->left, p, q);
        }
        if(p->val > root->val && q->val > root->val){
            //right answer
            return lowestCommonAncestor(root->right, p, q);
        }
        //else
        return root;
    }
};