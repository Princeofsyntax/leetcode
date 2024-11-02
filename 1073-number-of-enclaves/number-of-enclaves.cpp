class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>&vis ,vector<vector<int>>& board){
        if(board[i][j] == 0)return;
        if(vis[i][j])return;
        vis[i][j] = 1;
        if(j+1 < board[0].size()) dfs(i, j+1,vis,board);
        if(j-1 >= 0)  dfs(i, j-1, vis, board);
        if(i+1 < board.size())  dfs(i+1,j,vis, board);
        if(i-1 >= 0)  dfs(i-1, j, vis, board);

    }
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int j = 0; j < m; j++){
            if(board[0][j] == 1) dfs(0,j,vis, board);
            if(board[n-1][j] == 1) dfs(n-1,j,vis,board);
        }
        for(int i = 1; i < n-1; i++){
            if(board[i][0] == 1) dfs(i,0,vis,board);
            if(board[i][m-1] == 1) dfs(i,m-1,vis,board);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 1)ans++;
            }
        }
        return ans;
    }
};