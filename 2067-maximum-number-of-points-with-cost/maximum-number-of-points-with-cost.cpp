class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();    // Number of rows
        int n = points[0].size(); // Number of columns
        
        // Previous row's max points for each column
        vector<long long> prevRow(n, 0);
        
        // Initialize the first row as the previous row
        for (int j = 0; j < n; ++j) {
            prevRow[j] = points[0][j];
        }
        
        for (int i = 1; i < m; ++i) {
            vector<long long> left(n, 0), right(n, 0), currRow(n, 0);
            
            // Calculate left maximums
            left[0] = prevRow[0];
            for (int j = 1; j < n; ++j) {
                left[j] = max(left[j - 1] - 1, prevRow[j]);
            }
            
            // Calculate right maximums
            right[n - 1] = prevRow[n - 1];
            for (int j = n - 2; j >= 0; --j) {
                right[j] = max(right[j + 1] - 1, prevRow[j]);
            }
            
            // Calculate current row's max points for each column
            for (int j = 0; j < n; ++j) {
                currRow[j] = points[i][j] + max(left[j], right[j]);
            }
            
            // Update the previous row with the current row
            prevRow = currRow;
        }
        
        // The answer is the maximum value in the last row
        return *max_element(prevRow.begin(), prevRow.end()); 
    }
};