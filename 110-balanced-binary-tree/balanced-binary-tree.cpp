class Solution {
public:
    bool balanced = true;

    int height(TreeNode* root){
        if(!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);
        
        //check for current node, isBalanced -->during recursion of height
        if(balanced && abs(lh-rh) > 1){
            balanced = false;
        }
        return max(lh,rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        height(root);
        return balanced;
    }
};