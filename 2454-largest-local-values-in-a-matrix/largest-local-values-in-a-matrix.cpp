class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int size = grid.size();

        vector<vector<int>>ans(size-2, vector<int>(size-2));
        int newSize = size-2;
        for(int row = 0; row < newSize; row++){
            for(int col = 0; col < newSize; col++){
                //now iterate on 3*3 matrix to store maxima in result
                for(int i = row; i <= row+2; i++){
                    for(int j = col; j <= col+2; j++){
                        ans[row][col] = max(ans[row][col], grid[i][j]);
                    }
                }
            }
        }
       return ans;
    }
};