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
class BSTIterator {
public:
    stack<TreeNode*>st;
    // reverse -> true -> before && reverse -> false -> next
    bool reverse = true;
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* nextNode = st.top();
        st.pop();
        if(!reverse)
            pushAll(nextNode->right);
        else 
            pushAll(nextNode->left);
        return nextNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
   void pushAll(TreeNode* node){
      for( ; node != nullptr ; ){
        st.push(node);
        if(reverse) node = node->right;
        else node = node->left;
      }
   }
};

class Solution {
public:

    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();// provide before element
        while(i < j){
            if(i + j == k)return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};