class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int,int,int>>>graph(n);
        for(const auto& edge : edges){
            int u = edge[0], v = edge[1], start = edge[2], end = edge[3];
            graph[u].emplace_back(v,start,end);
        }
        using pp = pair<int,int>;
        priority_queue<pp, vector<pp>, greater<pp>>pq; //time, node
        vector<int> dist(n, INT_MAX); // minTime for each node
        dist[0] = 0;
        pq.emplace(0,0); 

        while(!pq.empty()){
            auto pair = pq.top();
            pq.pop();
            int currTime = pair.first;
            int node = pair.second;
            if(node == n-1)return currTime;
            if(currTime > dist[node]) continue;
            for(const auto& [nei, start, end] : graph[node]){
                if(currTime > end)continue;
                int timeToReach = max(currTime,start)+1;
                if(timeToReach >= dist[nei])continue;
                dist[nei] = timeToReach;
                pq.emplace(timeToReach,nei);
            }
        }
        return -1;
    }
};