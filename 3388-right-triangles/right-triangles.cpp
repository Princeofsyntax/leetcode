class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<int>row;
        vector<int>col;
        for(int i=0;i<grid.size();i++)
        {
            int countone=0;
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1) countone++;
                
            }
            row.push_back(countone);
        }
        for(int i=0;i<grid[0].size();i++)
        {
            int countone=0;
            for(int j=0;j<grid.size();j++)
            {
                if(grid[j][i]==1) countone++;
                
            }
            col.push_back(countone);
        }
       
        long long int maxi=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {

                if(grid[i][j]==1)
             {
                   
                    if(row[i]>=2 && col[j]>=2){
                           maxi+=(row[i]-1)*(col[j]-1);
                    }
                       
                                           
                }
            
            }
        }
        return maxi;
    }
};