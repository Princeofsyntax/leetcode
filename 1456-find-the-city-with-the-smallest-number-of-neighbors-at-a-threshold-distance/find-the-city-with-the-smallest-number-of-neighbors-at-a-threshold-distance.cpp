class Solution {
public:
    int shortestDistanceDIJKSTRA(int src, int n, unordered_map<int,list<pair<int,int>>>&adjList, int &distanceThres)
    {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st; //{distance,node}
        // initial step
        dist[src] = 0;
        st.insert(make_pair(0, src));
        int reachableCities = 0; //cities at most having distanceThresold distance
        

        while (!st.empty())
        {
            // fetch the smallest or first element from the set
            auto topElement = *(st.begin()); // if we use st.begin() then it will provide iterator hence we dereferenced it
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop from set
            st.erase(st.begin()); // erases the first element
            
            if(node != src && nodeDistance <= distanceThres){
              ++reachableCities;
            }

            // neighbour traverse
            for (auto nbr : adjList[node])
            {
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    // now i have to update the distance
                    auto result = st.find(make_pair(dist[nbr.first], nbr.first)); // we have to search in set the previous entry
                    // if entry is found-->remove
                    if (result != st.end())
                    {
                        st.erase(result);
                    }
                    // update
                    dist[nbr.first] = nodeDistance + nbr.second;
                    // insert
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }
        return reachableCities;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //we will use djkstra
        unordered_map<int,list<pair<int,int>>>adjList;
        for(auto edge : edges){
            int &u = edge[0];
            int &v = edge[1];
            int &w = edge[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        int city = 0; //which city is the answer
        int minReachableCities = INT_MAX;

        for(int u = 0; u < n; u++){
            int reachableCitiesCount = shortestDistanceDIJKSTRA(u,n,adjList,distanceThreshold);
            if(reachableCitiesCount <= minReachableCities){
                minReachableCities = reachableCitiesCount;
                city = u;
            }
        }
        return city;
    }
};