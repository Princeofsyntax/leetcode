class Solution {
public:
    vector<TreeNode*> allPossibleBSTS(int start, int end){
        //base case
        if(start > end) return {0};
        if(start == end) return {new TreeNode(start)};

        vector<TreeNode*>ans;
        for(int i = start; i <= end; i++)
        {
            vector<TreeNode*>left = allPossibleBSTS(start, i-1);
            vector<TreeNode*>right = allPossibleBSTS(i+1,end);

            for(int j = 0; j < left.size(); j++)
            {
                for(int k = 0; k< right.size(); k++)
                {
                    //To find various combination 
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return allPossibleBSTS(1,n);
    }
};