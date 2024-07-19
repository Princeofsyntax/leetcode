class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return {};
        int m = matrix[0].size();
        
        vector<int> minInRow(n, INT_MAX);
        vector<int> maxInCol(m, INT_MIN);

        // Find the minimum in each row and the maximum in each column in a single pass
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < minInRow[i]) {
                    minInRow[i] = matrix[i][j];
                }
                if (matrix[i][j] > maxInCol[j]) {
                    maxInCol[j] = matrix[i][j];
                }
            }
        }

        vector<int> ans;

        // Find the lucky numbers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == minInRow[i] && matrix[i][j] == maxInCol[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};