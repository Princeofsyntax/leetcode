class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> direction{{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        set<pair<int,int>> st;
        for(const auto& ob : obstacles){
            st.insert({ob[0], ob[1]});
        }
        
        int x = 0, y = 0;  
        int dir = 0;       
        int maxDist = 0;   
        
        for(int cmd : commands){
            if(cmd == -2) {
                // Turn left 
                dir = (dir + 3) % 4;
            }
            else if(cmd == -1) {
                // Turn right 
                dir = (dir + 1) % 4;
            }
            else {
                for(int step = 0; step < cmd; ++step){
                    int newX = x + direction[dir][0];
                    int newY = y + direction[dir][1];
                    
                    if(st.find({newX, newY}) != st.end()){
                        break;
                    }
                    
                    x = newX;
                    y = newY;
                }
                maxDist = max(maxDist, x*x + y*y);
            }
        }
        
        return maxDist;
    }
};