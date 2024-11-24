class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long totalSum = 0;
        int negativeCount = 0;
        int smallestAbsValue = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = matrix[i][j];
                totalSum += abs(val);
                if (val < 0) {
                    negativeCount++;
                }
                smallestAbsValue = min(smallestAbsValue, abs(val));
            }
        }
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * smallestAbsValue;
        }
        return totalSum;
    }
};