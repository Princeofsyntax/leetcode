class Solution {
public:
    vector<TreeNode*>ans;
    unordered_map<string,int>subTreeMap; //stores encoded form of nodes with its occurence
    string preOrder(TreeNode* root){
        if(!root) return "N";

        string curr = to_string(root->val); //int to string
        string l = preOrder(root->left);
        string r = preOrder(root->right);
        string s = curr + "," + l + "," + r; //encoded form of each node

        if(subTreeMap.find(s) != subTreeMap.end()){
            //found
            if(subTreeMap[s] == 1) ans.push_back(root); //pushing answer when first time duplicacy occurs
            subTreeMap[s]++; //increment 
        }
        else{
            //not found
            subTreeMap[s] = 1;
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};