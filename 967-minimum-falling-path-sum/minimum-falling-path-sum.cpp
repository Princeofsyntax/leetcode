class Solution {
public:
    // int helper(int i, int j, vector<vector<int>>& matrix, int n,  vector<vector<int>>&dp){
    //     if(i == n-1)return matrix[i][j];
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int minSum = INT_MAX;
    //     int moveDown = matrix[i][j] + helper(i+1, j, matrix, n, dp);
    //     int moveLeftDiag = INT_MAX; 
    //     int moveRightDiag = INT_MAX;
    //     if(j+1 < n) moveRightDiag = matrix[i][j]  + helper(i+1, j+1, matrix, n, dp);
    //     if(j-1 >= 0) moveLeftDiag = matrix[i][j] + helper(i+1, j-1, matrix, n, dp);

    //     return dp[i][j] = min(moveDown, min(moveLeftDiag, moveRightDiag));
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int minSum = INT_MAX;
        // vector<vector<int>>dp(n, vector<int>(n, -1));
        // for(int j = 0; j < n; j++){
        //    minSum = min(minSum, helper(0, j, matrix, n, dp));
        // }
        // return minSum;

        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i = n-2; i>=0; i--){
            for(int j = 0; j < n;j++){
                int up = matrix[i][j] + dp[i+1][j];
                int leftDiag = (j - 1 >= 0) ? matrix[i][j] + dp[i + 1][j - 1] : INT_MAX;
                int rightDiag = (j + 1 < n) ? matrix[i][j] + dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = min(up,min(leftDiag,rightDiag));
            }
        }

    // Final answer
    return *min_element(dp[0].begin(), dp[0].end());
    }
};