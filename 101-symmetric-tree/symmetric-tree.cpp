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
        
    bool isMirror(TreeNode *p, TreeNode *q)
    {
        // Traverse both trees simultaneously
        if (!p && !q)
            return true;
        if (p && q)
        {
            //we will call function isMirror left for first half and right for second half to get mirror and vice-versa
            return (p->val == q->val) 
                     && isMirror(p->left, q->right) 
                     && isMirror(p->right, q->left);
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left , root->right);
    }
};