class Solution {
public:
   
    // Global variables to store the adjacency list, subtree sum, and node counts
    unordered_map<int, vector<int>> adjList;
    vector<int> subtreeSum;
    vector<int> count;

    // Function to add an edge to the adjacency list
    void addEdge(int u, int v) {
        // Undirected graph, so adding both edges
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Depth-first search to compute subtree sum and node counts
    void dfs1(int u, int parent) {
        count[u] = 1; // Initially, there is one node in the subtree rooted at u
        subtreeSum[u] = 0; // Initialize subtree sum for node u
        for (int v : adjList[u]) {
            if (v != parent) {
                // Recursive call to compute subtree sums and counts for children nodes
                dfs1(v, u);
                count[u] += count[v]; // Update node count for node u
                subtreeSum[u] += subtreeSum[v] + count[v]; // Update subtree sum for node u
            }
        }
    }

    // Depth-first search to update subtree sums after the initial computation
    void dfs2(int u, int parent, int n) {
        for (int v : adjList[u]) {
            if (v != parent) {
                // Update subtree sum for node v based on the sum of distances from node u
                subtreeSum[v] = subtreeSum[u] - count[v] + n - count[v];
                // Recursive call for node v
                dfs2(v, u, n);
            }
        }
    }

    // Main function to compute the sum of distances in the tree
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // Clear the global variables
        adjList.clear();
        count.clear();
        subtreeSum.clear();
        
        // Resize the vectors to the size of the tree
        count.resize(n);
        subtreeSum.resize(n);

        // Construct the adjacency list
        for (auto edge : edges) {
            addEdge(edge[0], edge[1]);
        }

        // Compute subtree sum and node counts using depth-first search
        dfs1(0, -1);

        // Update subtree sums for all nodes
        dfs2(0, -1, n);

        // Return the computed subtree sums
        return subtreeSum;
    }

};