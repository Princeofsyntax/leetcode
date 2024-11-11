class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int numNodes = s.size();  
        vector<int> tree[numNodes];  
        vector<int> matchingNodes[26];  
        for (int i = 1; i < numNodes; ++i) {
            tree[parent[i]].push_back(i);
        }

        vector<int> subtreeSizes(numNodes);  
        auto dfs = [&](auto&& dfs, int node, int parentNode) -> void {
            subtreeSizes[node] = 1;  
            int charIndex = s[node] - 'a';  
            
            matchingNodes[charIndex].push_back(node);  
            
            for (int child : tree[node]) {
                dfs(dfs, child, node);  
            }
            
            int closestAncestor = matchingNodes[charIndex].size() > 1 ? matchingNodes[charIndex][matchingNodes[charIndex].size() - 2] : parentNode;
            
            if (closestAncestor >= 0) {
                subtreeSizes[closestAncestor] += subtreeSizes[node];
            }
            
           matchingNodes[charIndex].pop_back();
        };

        dfs(dfs, 0, -1);
        
        return subtreeSizes;  
    }
};