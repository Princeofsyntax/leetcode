class Solution {
public:
    bool checkBound(vector<vector<int>>& grid, vector<pair<int,int>>&v){
        int m = grid.size();
        int n = grid[0].size();
        for(auto pt: v){
            if(pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n){
               return false;
            }
        }
        return true;
    }

    bool getAllVertices(vector<vector<int>>& grid, vector<pair<int,int>>&v, pair<int,int>c, int &delta){
        //find vertices if possible
        pair<int,int>A(c.first - delta , c.second);
        pair<int,int>B(c.first , c.second + delta);
        pair<int,int>C(c.first + delta , c.second);
        pair<int,int>D(c.first , c.second - delta);
        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;

        if(checkBound(grid, v)){
            return true;
        }
        return false;
    }

    void getAllSum(vector<vector<int>>& grid, int &cx, int &cy, priority_queue<int>&pq){
        //push rhombus sum of rhombus with area 0
        pq.push(grid[cx][cy]);
        //consider each cell and create all possible rhombus around it
        int delta = 1;
        vector<pair<int,int>>v(4);  //4 points forms rhombus
        while(getAllVertices(grid, v, {cx, cy}, delta)){
            //valid points
            pair<int,int>&A = v[0];
            pair<int,int>&B = v[1];
            pair<int,int>&C = v[2];
            pair<int,int>&D = v[3];
            int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

             //all cells between AB
             for(int i = 1; i < (B.first - A.first); ++i){
                 csum += grid[A.first+i][A.second+i];
             }
             //all cells between BC
             for(int i = 1; i < (C.first - B.first); ++i){
                 csum += grid[B.first+i][B.second-i];
             }
             //all cells between CD
             for(int i = 1; i < (C.first - D.first); ++i){
                 csum += grid[C.first-i][C.second-i];
             }
             //all cells between DA
             for(int i = 1; i < (D.first - A.first); ++i){
                 csum += grid[D.first-i][D.second+i];
             }
           pq.push(csum); //rhombus sum has been included 
           ++delta; //to calculate other rhombuses which can be formed via same cell as center
        }
    }

    bool canPushIt(vector<int>&ans, int top){
        for(auto val : ans){
            if(val == top){
                return false;
            }
        }
        return true;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int>ans;
        priority_queue<int>pq; //maxHeap
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                getAllSum(grid,i,j,pq);
            }
        }
        while(!pq.empty() && ans.size()<3){
            int top = pq.top();
            pq.pop();
            if(canPushIt(ans,top)){
                //as if same answer comes than we have to take it once only
               ans.push_back(top);
            }
        }
        return ans;
    }
};