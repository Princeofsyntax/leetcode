class Solution {
public:
    bool helper(vector<vector<int>>& graph, int start, vector<int>&colour){
        queue<int>q;
        colour[start] = 0;
        q.push(start);
        while(!q.empty()){
            int fNode = q.front();
            q.pop();
            for(const auto& agla : graph[fNode]){
                if(colour[agla] == -1){
                    colour[agla] = !colour[fNode];
                    q.push(agla);
                }
                else if(colour[agla] == colour[fNode]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colour(n,-1);
        for(int i = 0; i < n; i++){
            if(colour[i] == -1 && !helper(graph, i, colour))return false;  ;
        }
        return true;
    }
};