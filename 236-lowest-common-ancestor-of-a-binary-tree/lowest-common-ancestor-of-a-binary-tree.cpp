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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL){
            return NULL;
        }

        //check for p and q (we will move upward after this to get the lowest common ancestor)
        if(root->val == p->val ){
            return p;
        }
        if(root->val == q->val){
            return q;
        }

        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns == NULL && rightAns == NULL){
            return NULL;
        }
        else if(leftAns != NULL && rightAns == NULL){
            //both p and q are in left
            return leftAns;
        }
        else if(leftAns==NULL && rightAns != NULL){
            //both p and q are in right
            return rightAns;
        }
        else{
            //current node is the LCA
            return root;
        }

    }
};