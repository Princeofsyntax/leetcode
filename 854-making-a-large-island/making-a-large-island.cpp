class Solution {
public:
    vector<int> dir={-1,0,1,0,-1};

    bool isValid(int& n,int& x,int& y){
        return (x>=0 and x<n and y>=0 and y<n);
    }

    int markIsland(vector<vector<int>>& grid,int& island_number,int& n,int x,int y){
        grid[x][y] = island_number;
        int count = 1;
        for(int i=0;i<4;++i){
            int newX = x + dir[i];
            int newY = y + dir[i+1];
            if(isValid(n,newX,newY) and grid[newX][newY]==1)
                count += markIsland(grid,island_number,n,newX,newY);
        }
        return count;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> island_size;
        int island_number=2; // to provide each island a unique id and then push in map with its size ( 0, 1 already reserved via question)

        //Mark island
        for(int x=0;x<n;++x){
            for(int y=0;y<n;++y){
                if(grid[x][y]==1){
                    int island = markIsland(grid,island_number,n,x,y);
                    island_size[island_number]=island;
                    island_number++;
                }
            }
        }
        
        //Try to convert each 0 to 1 one by ond
        int max_size=0;
        for(int x=0;x<n;++x){
            for(int y=0;y<n;++y){
                if(grid[x][y]==0){
                    set<int> islands;
                    for(int i=0;i<4;++i){
                        int newX = x + dir[i];
                        int newY = y + dir[i+1];
                        if(isValid(n,newX,newY))
                            islands.insert(grid[newX][newY]);
                    }
                    //Iterate and find total size of current island
                    int curr_island = 1; 
                    for(int key: islands)
                        curr_island += island_size[key];
                    
                    max_size = max(max_size,curr_island);
                }
            }
        }
        return max_size==0? n*n : max_size;
    }
};