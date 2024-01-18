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
    
int height(TreeNode* root){
    //base case
        if(root == NULL){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int ans = max(leftHeight , rightHeight) +1 ;//+1 is done to consider root node also

        return ans;

}

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        //option1
        int op1 = diameterOfBinaryTree(root->left);
        //option2
        int op2 = diameterOfBinaryTree(root->right);
        //option 3(main)
        int op3 = height(root->left) +  height(root->right); // we have to count no. of edges
        int ans = max(op1, max(op2,op3));

        return ans;

    }
};