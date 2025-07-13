class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); //path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return false; //already connected

        if(rank[rootX] < rank[rootY])
            swap(rootX, rootY);
        
        parent[rootY] = rootX;
        if(rank[rootX] == rank[rootY])
            rank[rootX]++;
        
        return true;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        //sort edges by weight
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        //kruskal's algorithm to build MST
        DSU dsu(n);
        vector<int> mstWeights;

        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if(dsu.unite(u, v)) {
                mstWeights.push_back(w); //include edge in MST
            }
        }

        //remove k-1 largest edges to get k components
        int removeEdges = k - 1;
        sort(mstWeights.begin(), mstWeights.end(), greater<int>()); //sort descending

        while(removeEdges-- && !mstWeights.empty()) {
            mstWeights.erase(mstWeights.begin()); //remove the largest edge
        }

        //result is the maximum edge weight left
        if(mstWeights.empty()) return 0;

        return mstWeights[0];
    }
};