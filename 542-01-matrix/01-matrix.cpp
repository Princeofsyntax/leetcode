class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>, int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        vector<vector<int>>direction = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto pair = q.front();
            q.pop();
            int x = pair.first.first;
            int y = pair.first.second;
            int distance = pair.second;
            
            for(int i = 0; i < 4; i++){
                int newX = x + direction[i][0];
                int newY = y + direction[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                   if(!visited[newX][newY]){
                      visited[newX][newY] = 1;
                      dist[newX][newY] = distance+1;
                      q.push({{newX,newY},distance+1});
                   }
                }
            }
        }

        return dist;
    }
};