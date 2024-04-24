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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
        {
            //depth 1 here is at root
            TreeNode* newNode = new TreeNode(v);
            newNode->left = root;
            return newNode;
        }

        int depth = 0;
        queue<TreeNode*>q({root}); //initialising by pushing root

        while(!q.empty())
        {
            depth++;
            for(int i = q.size(); i > 0 ; i--){
                TreeNode* currNode = q.front();
                q.pop();

                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
                if(depth == d-1){
                    TreeNode* currLeft = currNode->left;
                    TreeNode* currRight = currNode->right;
                    currNode->left = new TreeNode(v);
                    currNode->right = new TreeNode(v);
                    currNode->left->left = currLeft;
                    currNode->right->right = currRight;
                }
            }
            if(depth == d-1){
                break;
            }
        }
        return root;
    }
};