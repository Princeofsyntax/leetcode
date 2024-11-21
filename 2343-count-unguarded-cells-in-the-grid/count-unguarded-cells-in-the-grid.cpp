class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); 
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2; 
        }
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 3; 
        }
        vector<int> directions = {-1, 0, 1, 0, -1};
        for (auto& guard : guards) {
            for (int k = 0; k < 4; ++k) {
                int x = guard[0];
                int y = guard[1];
                int dx = directions[k];
                int dy = directions[k + 1];
                while (true) {
                    x += dx;
                    y += dy;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] >= 2) {
                        break;
                    }
                    if (grid[x][y] == 0) {
                        grid[x][y] = 1;  
                    }
                }
            }
        }
        int unguardedCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) { 
                    ++unguardedCount;
                }
            }
        }
        return unguardedCount;
    }

};
