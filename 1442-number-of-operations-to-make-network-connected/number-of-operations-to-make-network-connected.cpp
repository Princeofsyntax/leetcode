class Solution {
public:
    int findparent(vector<int> &parent, int node)
        {
            if (parent[node] == node)
            {
                return node;
            }
            return parent[node] = findparent(parent, parent[node]); // path compression by storing parent[node] so that it can be used later// recursion to reach main parent node (whose parent is node itself)
        }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
        {
            u = findparent(parent, u);
            v = findparent(parent, v);
            if (rank[u] < rank[v])
            {
                parent[u] = v;
                // increase rank of parent
                rank[v]++;
            }
            else
            {
                // when individual node present or other condition of "if"
                parent[v] = u;
                rank[u]++;
            }
        }

    int makeConnected(int n, vector<vector<int>>& connections)
        {
            //For n components we need (n-1) cables 
            //Use disjoint set (krushkal's) to get extra edges 
            //Firstly we have to find no. of connected components and extra edges
            vector<int>parent(n);
            vector<int>rank(n,0);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
            int extraEdges = 0;
            for(auto connection : connections){
                int u = connection[0];
                int v = connection[1];

                u = findparent(parent, u);
                v = findparent(parent, v);

                if(u != v){
                    unionSet(u, v, parent, rank);
                }
                else{
                    //same parent --> belongs to one component --> extra edge
                    ++extraEdges;
                }
            }
            int nocc = 0; //no. of connected components
            for(int i = 0; i < n; i++){
                if(parent[i] == i){
                    //as via disjoint set and path compression, we get one component with only one parent 
                    //So we can count parent nodes to get no. of components
                    nocc++;
                }
            }
            int ans = nocc - 1; //cables needed
            if(extraEdges >= ans){
                return ans;
            }
            else{
                return -1;
            }
        }
};