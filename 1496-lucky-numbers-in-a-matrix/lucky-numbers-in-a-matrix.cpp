class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 0) return {};

        vector<int>minInRow(n);
        vector<int>maxInCol(m);

        int minRow = INT_MAX;
        int maxCol = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                 if(matrix[i][j] < minRow){
                    minRow = matrix[i][j];
                 }
            }
            minInRow[i] = minRow;
            minRow = INT_MAX;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                 if(matrix[j][i] > maxCol){
                    maxCol = matrix[j][i];
                 }
            }
            maxInCol[i] = maxCol;
            maxCol = INT_MIN;
        }
        
        vector<int>ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == minInRow[i] && matrix[i][j] == maxInCol[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};