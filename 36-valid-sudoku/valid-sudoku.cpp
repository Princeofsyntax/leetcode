class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Create three 9x9 matrices for rows, columns, and sub-boxes respectively.
        vector<vector<bool>> rowCheck(9, vector<bool>(9, false));
        vector<vector<bool>> colCheck(9, vector<bool>(9, false));
        vector<vector<bool>> subBoxCheck(9, vector<bool>(9, false));

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char currentChar = board[row][col];
              
                if (currentChar == '.') continue;

                int num = currentChar - '0' - 1;

                int subBoxIndex = (row / 3) * 3 + (col / 3); //subBox index

                if (rowCheck[row][num] || colCheck[col][num] || subBoxCheck[subBoxIndex][num]) {
                    return false;
                }

                // Mark the number as used in the current row, column, and sub-box.
                rowCheck[row][num] = true;
                colCheck[col][num] = true;
                subBoxCheck[subBoxIndex][num] = true;
            }
        }

        // If all checks pass, then the board is valid.
        return true;
    }
};