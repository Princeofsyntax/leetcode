class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>&adj, int start, int target){
        vector<int> stk = {start};
        unordered_set<int> lookup; //visited nodes
        while (!empty(stk)) {
            auto node = stk.back(); 
            stk.pop_back();
            if (node == target) {
                return true;
            }
            if (!adj.count(node)) {
                //no neighbours
                continue; //this will skip the iteration for current node and will move to other node connected to start
            }
            for (auto neighbour : adj.at(node)) {
                if (lookup.count(neighbour)) {
                    continue; //already visited
                }
                lookup.emplace(neighbour); //insert
                stk.emplace_back(neighbour); //insert
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>adj;

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].emplace_back(v); //emplace_back works same as push_back 
            adj[v].emplace_back(u);
        }

        return dfs(adj, source, destination);
    }
};