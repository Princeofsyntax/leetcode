class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        deque<pair<int, int>> dq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        dq.push_front({0, 0});
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newDist = dist[x][y] + grid[nx][ny];
                    //If a shorter path to (nx, ny) is found
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny}); // Prioritize cells with 0 cost
                        } else {
                            dq.push_back({nx, ny}); 
                        }
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};