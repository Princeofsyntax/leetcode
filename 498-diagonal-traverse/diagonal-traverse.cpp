class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return {};
        }

        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        int row = 0, col = 0;
        bool goingUp = true; 

        while (ans.size() < m * n) {
            ans.push_back(mat[row][col]);

            if (goingUp) {
                if (col == n - 1) {
                    row++;
                    goingUp = false;
                }
                else if (row == 0) {
                    col++;
                    goingUp = false;
                }
                else {
                    row--;
                    col++;
                }
            } else { 
                if (row == m - 1) {
                    col++;
                    goingUp = true;
                }
                else if (col == 0) {
                    row++;
                    goingUp = true;
                }
                else {
                    row++;
                    col--;
                }
            }
        }
        return ans;
    }
};