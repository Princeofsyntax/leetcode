class Solution {
public:
    # define pip pair<int, pair<int,int>>
    bool isValid(int x, int y, int m, int n){
        if(x < m && y < n && x >= 0 && y >= 0)return true;
        return false;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if(m < 3 || n < 3)return 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        priority_queue<pip, vector<pip>,greater<pip>>pq;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    pq.push({heightMap[i][j], {i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        int ans = 0;
        int level = 0;
        vector<int>dir = {-1,0,1,0,-1};
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int height = node.first;
            int x = node.second.first;
            int y = node.second.second;
            level = max(level, height);
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if(isValid(nx,ny,m,n) && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    pq.push({heightMap[nx][ny], {nx,ny}});
                    if(heightMap[nx][ny] < level){
                        // water can be traped
                        ans += level - heightMap[nx][ny];
                    }
                }
            }
        }
        return ans;
    }
};