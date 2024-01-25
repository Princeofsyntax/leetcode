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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr = root;
        while(curr){
            //left node is NULL, visit it, and go right
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right; //back movement as link is established
            }
            //left node is not NULL
            else{
                //find inorder predecessor
                TreeNode* pred = curr->left;
                while(pred->right != curr  &&  pred->right){
                    pred = pred->right;
                }
                //if pred right node is NULL then go left after establishing link form predecessor(pred) to current(curr)
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    //left is already visited , go right after visiting curr Node , while removing the link
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};