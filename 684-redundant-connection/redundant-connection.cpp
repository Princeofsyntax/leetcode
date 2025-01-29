class Solution {
public:
    int find(int node, vector<int>&parent){
        if(parent[node] != node){
            parent[node] = find(parent[node], parent);
        }
        return parent[node];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int rootu = find(u,parent);
            int rootv = find(v,parent);
            if(rootu == rootv)return edge;
            parent[rootv] = rootu;
        }
        return {};
    }
};