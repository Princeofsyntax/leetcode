class Solution {
public:
    int dijkstra(const vector<vector<int>>& moveTime, pair<int, int> src, pair<int, int> dst) {
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[src.first][src.second] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src.first, src.second});
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while (!pq.empty()) {
            auto [currDist, x, y] = pq.top();
            pq.pop();
            if (make_pair(x, y) == dst) return currDist;
            if (currDist > dist[x][y]) continue;
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newDist = max(moveTime[nx][ny], currDist) + 1;
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        pq.push({newDist, nx, ny});
                    }
                }
            }
        }
        return -1; 
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        return dijkstra(moveTime, {0, 0}, {moveTime.size() - 1, moveTime[0].size() - 1});
    }
};
