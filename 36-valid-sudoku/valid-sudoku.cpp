class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> check(9, false);

        // Check every row
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (check[num - 1] == true) {
                    return false;
                }
                check[num - 1] = true;
            }
            fill(check.begin(), check.end(), false);
        }
        
        // Check every column
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                int num = board[j][i] - '0';
                if (check[num - 1] == true) {
                    return false;
                }
                check[num - 1] = true;
            }
            fill(check.begin(), check.end(), false);
        }

        // Check every 3x3 block
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                for (int l = i; l < i + 3; l++) { 
                    for (int k = j; k < j + 3; k++) { 
                        if (board[l][k] == '.') continue;
                        int num = board[l][k] - '0';
                        if (check[num - 1] == true) {
                            return false;
                        }
                        check[num - 1] = true;
                    }
                }
                fill(check.begin(), check.end(), false);
            }
        }

        return true;
    }
};