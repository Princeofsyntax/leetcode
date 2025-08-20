class Solution {
private:
    vector<vector<int>> memo;

    int solve(int i, int j, const vector<vector<int>>& matrix) {
        if (i < 0 || j < 0 || matrix[i][j] == 0) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int top = solve(i - 1, j, matrix);
        int left = solve(i, j - 1, matrix);
        int topLeft = solve(i - 1, j - 1, matrix);

        return memo[i][j] = 1 + min({top, left, topLeft});
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        
        memo.assign(n, vector<int>(m, -1));

        int totalCount = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                totalCount += solve(i, j, matrix);
            }
        }

        return totalCount;
    }
};