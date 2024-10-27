class Solution {
public:
    int countSquaresHelper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return 0; 
    if (matrix[i][j] == 0) return 0; 
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = min({countSquaresHelper(i - 1, j, matrix, dp),
                    countSquaresHelper(i, j - 1, matrix, dp),
                    countSquaresHelper(i - 1, j - 1, matrix, dp)}) + 1;

    return dp[i][j];
}


    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int totalSquares = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                totalSquares += countSquaresHelper(i, j, matrix, dp);
            }
        }

        return totalSquares;
    }
};