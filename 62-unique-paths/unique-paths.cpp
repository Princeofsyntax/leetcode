class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,0));

        // fill the entire first row and first column as there is only one way to reach
        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }
        for(int j = 0; j < m; j++){
            dp[j][0] = 1;
        }

        // Now fill the table 
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];

    }
};