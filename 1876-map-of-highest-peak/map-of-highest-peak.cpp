class Solution {
public:
    #define pp pair<int, pair<int,int>>
    bool isSafe(int x, int y, int m, int n){
        if(x >= 0 && x < m && y >= 0 && y < n)return true;
        return false;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pp>q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                vis[i][j] = 1;
                q.push({0,{i,j}});
                isWater[i][j] = 0;
                }
            }
        }
        vector<int>dir{1,0,-1,0,1};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int dis = node.first;
            int x = node.second.first;
            int y = node.second.second;
            for(int i = 0; i <4; i++){
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if(isSafe(nx, ny, m, n) && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    isWater[nx][ny] = 1 + dis;
                    q.push({1 + dis, {nx,ny}});
                }
            }
        }
        return isWater;
    }
};