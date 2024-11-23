class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        for (int i = 0; i < m; i++) {
            int emptySpot = n - 1; 
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    emptySpot = j - 1;
                } else if (box[i][j] == '#') {
                   swap(box[i][j], box[i][emptySpot]);
                    emptySpot--; 
                }
            }
        }
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }
        return rotatedBox;
    }
};