class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int &x, int &y){
        //x and y will provide coordinate for bottom right and i,j will provide coordinate for top left
        //base case
        if(i < 0 || j < 0 || i == land.size() || j == land[0].size() ){
           return;
        } 
        if(land[i][j] != 1) return;
        
        land[i][j] = 2; //mark as visited
        //modify the x and y coordinates
        x = max(x, i);
        y = max(y, j);

        //recursion
        dfs(land, i+1, j,x, y);
        dfs(land, i, j+1,x, y);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        for(int i = 0; i < land.size(); i++){
            for(int j = 0; j < land[0].size(); j++){
                if(land[i][j] == 1){
                    int x = i;
                    int y = j;
                    dfs(land, i, j, x, y);
                    ans.push_back({i, j, x, y});
                }
            }
        }
        return ans;
    }
};