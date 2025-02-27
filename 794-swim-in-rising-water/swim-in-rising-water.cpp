class Solution {
public:
    #define pp pair<int,pair<int,int>>
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        vector<vector<int>> minTime(n, vector<int>(n, INT_MAX));
        priority_queue<pp, vector<pp>, greater<pp>>pq;

        pq.push({grid[0][0], {0, 0}});
        minTime[0][0] = grid[0][0];
        
        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;
            
            if (r == n - 1 && c == n - 1) return time;
            
            for (auto& d : directions) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    int newTime = max(time, grid[nr][nc]);
                    if (newTime < minTime[nr][nc]) {
                        minTime[nr][nc] = newTime;
                        pq.push({newTime, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};