class Solution {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    int dfs(int src, int n){
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st; //{distance,node}
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;
            st.erase(st.begin()); 
            for (auto nbr : adjList[node])
            {
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    auto result = st.find(make_pair(dist[nbr.first], nbr.first)); 
                    if (result != st.end())
                    {
                        st.erase(result);
                    }
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }
        return dist[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        for(int i = 0; i < n-1; i++){
            adjList[i].push_back({i+1, 1}); 
        }

        vector<int>ans;

        for(const auto& querry : queries){
            int u = querry[0];
            int v = querry[1];
            adjList[u].push_back({v, 1});;
            ans.push_back(dfs(0,n));
        }

        return ans;
    }
};