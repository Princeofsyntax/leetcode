class Solution {
public:
    int movesHelper(TreeNode* node, int &M){
        if(!node) return 0;

        int leftMoves = movesHelper(node->left, M);
        int rightMoves = movesHelper(node->right, M);
          
        M += abs(leftMoves) + abs(rightMoves);
          
        return leftMoves + rightMoves + node->val - 1;
    }

    int distributeCoins(TreeNode* root) {
        if(!root) return 0;

        int requiredMoves = 0;

        movesHelper(root, requiredMoves);

        return requiredMoves;
    }
};