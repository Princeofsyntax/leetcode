class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        queue<tuple<int, int, int>> q; // (row, col, steps)
        q.emplace(entrance[0], entrance[1], 0);
        maze[entrance[0]][entrance[1]] = '+';

        vector<vector<int>>directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto [row, col, steps] = q.front();
            q.pop();
            
            for (const auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || maze[newRow][newCol] == '+') {
                    continue;
                }
                
                if ((newRow == 0 || newRow == m - 1 || newCol == 0 || newCol == n - 1) && maze[newRow][newCol] == '.') {
                    return steps + 1;
                }
                
                maze[newRow][newCol] = '+';
                q.emplace(newRow, newCol, steps + 1);
            }
        }
        
        return -1;
    }
};