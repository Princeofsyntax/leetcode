class Solution {
    private:
    void dfs(unordered_map<int,bool>&vis, vector<vector<int>>& isConnected, int src){
        vis[src] = true;
        //row --> src
        //col --> we will write a loop 
        //the blocks with 1 are neighbours
        int size = isConnected.size();
        for(int col = 0; col < size; col++){
            if(isConnected[src][col] == 1){
                //col is nbr (as edge is present)
                if(!vis[col]){
                   dfs(vis,isConnected,col);
                }
            }
        }
    }

    public:

        int findCircleNum(vector<vector<int>>& isConnected) {
            unordered_map<int,bool>visited;
            int count = 0;
            int n = isConnected.size();
            //i represents nodes here
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    dfs(visited,isConnected,i);
                    count++;
                }
            }
            return count;
        }
};