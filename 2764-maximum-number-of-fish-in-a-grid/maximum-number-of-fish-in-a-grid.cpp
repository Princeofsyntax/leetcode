class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};

    bool check(int i, int j, int &m, int &n, vector<vector<int>>& grid) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int bfs(int i, int j, int &m, int &n, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
        int fish = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;  
        fish += grid[i][j];  

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d];
                int ny = y + dir[d + 1];

                if (check(nx, ny, m, n, grid) && !vis[nx][ny] && grid[nx][ny] > 0) {
                    vis[nx][ny] = true;  
                    fish += grid[nx][ny];  
                    q.push({nx, ny});  
                }
            }
        }
        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int maxFish = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    maxFish = max(maxFish, bfs(i, j, m, n, vis, grid));
                }
            }
        }
        return maxFish;
    }
};