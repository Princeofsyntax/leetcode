
class Solution {
public:
    TreeNode* build(int &i, int min, int max, vector<int>& preorder){
       if(i >= preorder.size()){
           return nullptr;
       }
       TreeNode* root = nullptr;
       if(preorder[i] > min && preorder[i] < max){
           root = new TreeNode(preorder[i++]);
           root->left = build(i,min, root->val, preorder);
           root->right = build(i,root->val, max, preorder);
       }
       return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int min = INT_MIN, max = INT_MAX; //to create a range 
      int i = 0; //for iteration  
      return build(i,min,max,preorder);
    }
};