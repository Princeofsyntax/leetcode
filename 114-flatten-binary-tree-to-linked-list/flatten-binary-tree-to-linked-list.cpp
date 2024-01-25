
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            //curr->right will be normally handled as preorder
            if(curr->left){
              TreeNode* pred = curr->left;
              while(pred->right){
                  pred = pred->right;
              }

              pred->right = curr->right;
              curr->right = curr->left;
              curr->left = nullptr;
            }
            //use the given example to build the logic used 
            curr = curr->right;
        }
    }
};