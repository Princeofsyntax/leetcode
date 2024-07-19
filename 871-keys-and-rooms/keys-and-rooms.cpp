class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool>visited(n, false);
        stack<int>toVisit;
        
        // Start with room first
        toVisit.push(0);
        visited[0] = true;

        while(!toVisit.empty()){
            int current = toVisit.top();
            toVisit.pop();
            
            for(const auto&key : rooms[current]){
                if(!visited[key]){
                    visited[key] = true;
                    toVisit.push(key);
                }
            }

        }
        // check if all the rooms are visited
        for(const auto&vis : visited){
            if(!vis) return false;
        }
        return true;
    }
};