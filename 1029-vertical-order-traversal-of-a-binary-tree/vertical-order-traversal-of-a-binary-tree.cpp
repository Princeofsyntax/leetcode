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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        queue<pair<TreeNode*,pair<int,int>>>q; //Node, {row,col}
        q.push({root,{0,0}});
        //create a Multi-Map
        map<int,map<int,multiset<int>>>mp; //col -> {row: [x,y,x...]}
        //multiSet is used so that same values also get stored and multiSet stores them in sorted order

        while(!q.empty()){
            auto front = q.front();//auto is used as queue is storing complex dataStructure
            q.pop();
            TreeNode*&node = front.first;
            auto&coordinate = front.second; //taken by reference to avoid formation of copy
            int&row = coordinate.first;
            int&col = coordinate.second;

            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
            
        }
        //store final vertical order traversal into ans vector
        for(auto it:mp) //column wise sorted
        {
            auto&colMap = it.second; //a map
            vector<int>vline;
            for(auto colMapIt : colMap) //row wise sorted
            {
                auto&mSet = colMapIt.second;
                vline.insert(vline.end(), mSet.begin(), mSet.end()) ; //till vLine.end()-->from mSet.begin() to mSet.end()
            }
        ans.push_back(vline);
        }
        return ans;
    }
};