class Solution {
public:
    #define pp pair<int,pair<int,int>>

    bool check(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 0)return true;
        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) {
            return -1;
        }
        vector<vector<int>>dir = {{-1, -1},{-1,  0},{-1,  1},{ 0, -1}, { 0,  1}, { 1, -1}, { 1,  0},{ 1,  1}};
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pp>pq; // {dist, {i,j}}
        pq.push({1,{0,0}});
        vis[0][0] = true;
        while(!pq.empty()){
            auto combo = pq.front();
            pq.pop();
            int dist = combo.first;
            int x = combo.second.first;
            int y = combo.second.second;
            if(x == m-1 && y == n-1)return dist;
            for(const auto & d : dir){
                int nx = x + d[0];
                int ny = y + d[1];
                if(check(nx,ny,m,n,grid) && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    pq.push({dist+1, {nx,ny}});
                }
            }
        }
        return -1;
    }
};