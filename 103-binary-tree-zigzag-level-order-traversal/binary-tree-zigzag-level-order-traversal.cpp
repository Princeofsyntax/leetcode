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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        bool LtoR = true; //when true--> left to right and when false-->right to left
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int width = q.size(); //so that this much size vector is created
            vector<int> oneLevel(width);
            for(int i = 0; i < width; ++i){
                TreeNode* front = q.front();
                q.pop();
                int index = LtoR ? i : width-i-1; //if LtoR is true then push from begining else push from last in vector
                oneLevel[index] = front->val;

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            //toggle the direction
            LtoR = !LtoR;
            ans.push_back(oneLevel);
        }
        return ans;
    }
};