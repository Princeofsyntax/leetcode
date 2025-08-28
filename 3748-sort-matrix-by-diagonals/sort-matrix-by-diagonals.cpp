class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int row = 0; row < n; row++){
            vector<int>temp;
            for(int i = row, j = 0 ; i < n && j < n ; i++,j++){
                temp.push_back(grid[i][j]);
            }
            sort(temp.begin(), temp.end());
            for(int i = row, j = 0 ; i < n && j < n ; i++,j++){
                grid[i][j] = temp.back();
                temp.pop_back();
            }
        }

        for(int col = 1; col < n; col++){
            vector<int>temp;
            for(int i = 0, j = col; i < n && j < n ; i++,j++){
                temp.push_back(grid[i][j]);
            }
            sort(temp.rbegin(), temp.rend());
            for(int i = 0, j = col; i < n && j < n ; i++,j++){
                grid[i][j] = temp.back();
                temp.pop_back();
            }
        }
        return grid;
    }
};