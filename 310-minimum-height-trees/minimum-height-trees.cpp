class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //In a tree, the center nodes are those that, when removed, result in trees with the minimum possible height
        // Removing any of these center nodes would increase the height of the resulting trees ; So we have to calculate center nodes
        if( n == 1 || edges.empty()){
            return {0};
        }

        //create a undirected graph
        unordered_map< int , unordered_set<int>>graph;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }

        vector<int>ans; //to store the current leaf Nodes

        //iterate in graph to calculate for children node
        for( auto [currNode , child] : graph){
           if(child.size() == 1)
           {
               //means current node is leaf node as adjacent node is only one i.e, parent
               ans.push_back(currNode);
           }
        }

        while(n > 2){
            n = n - ans.size();
            vector<int>nextLeafNodes;
            //center nodes are at middle so we will eventually remove leaf nodes to reach to center nodes
            for(auto leaf : ans){
              //find parent of leaf
              int u = *graph[leaf].begin(); //as parent would be first which will be pushed in set corresponding to leaf
              graph[u].erase(leaf); //erasing leaf
              if(graph[u].size() == 1){
                //next leaf node
                nextLeafNodes.push_back(u);
              }
            }
            ans = nextLeafNodes;
        }
        return ans; //the final nodes in answer will provide minimum height trees
    }
};