class Solution {
private:
    void dfs(int x, int y,int oldColour, int newColor, map<pair<int,int>,bool>&vis, vector<vector<int>>& arr){
        vis[{x,y}] = true;
        arr[x][y] = newColor;
        //neighbours 
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size() && !vis[{newX,newY}] && arr[newX][newY] == oldColour){
                dfs(newX, newY, oldColour, newColor, vis, arr);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColour = image[sr][sc];
        map<pair<int,int>,bool>vis;
        vector<vector<int>> ans = image;
        dfs(sr,sc,oldColour,color,vis, ans);

        return ans;
    }
};