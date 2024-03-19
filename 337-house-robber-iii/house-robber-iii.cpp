class Solution {
public:
    //RECURSIVE 
    int solveRE(TreeNode* root){
        //base case
        if(!root) return 0;

        int robThisHouse = 0;
        int dontRobThisHouse = 0;

        //rob current house
         robThisHouse += root->val;
         if(root->left){
            robThisHouse += solveRE(root->left->left) + solveRE(root->left->right);
         }
         if(root->right){
            robThisHouse += solveRE(root->right->right) + solveRE(root->right->left);
         }

         //dont rob current house
         dontRobThisHouse = solveRE(root->left) + solveRE(root->right);

         return max(robThisHouse, dontRobThisHouse);
    }
    
    //DP SOL TOP DOWN (bottom up not possible generally here)
    int solveTD(TreeNode* root, unordered_map<TreeNode*, int>&dp){
        //base case
        if(!root) return 0;

        int robThisHouse = 0;
        int dontRobThisHouse = 0;
        //check
        if(dp.find(root) != dp.end()) return dp[root]; //answer is present

        robThisHouse += root->val;
        if(root->left){
            robThisHouse += solveTD(root->left->left, dp) + solveTD(root->left->right, dp);
         }
        if(root->right){
            robThisHouse += solveTD(root->right->right, dp) + solveTD(root->right->left, dp);
         }

        dontRobThisHouse = solveTD(root->left, dp) + solveTD(root->right, dp);
          //store
        dp[root] = max(robThisHouse, dontRobThisHouse);
        return dp[root];
    }

    int rob(TreeNode* root) {
        // return solveRE(root);//RECURSIVE

        unordered_map<TreeNode*, int>dp; //stores nodes with o/p
        return solveTD(root, dp); //dp top down

    }
};