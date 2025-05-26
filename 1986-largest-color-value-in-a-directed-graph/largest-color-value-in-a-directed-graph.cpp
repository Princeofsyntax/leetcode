class Solution {
    int dfs(int curr,vector<vector<int>>& adj,vector<int>& visited,vector<vector<int>>& longest,string& colors){
        if(visited[curr]==1)//Cycle found
            return INT_MAX;
        
        if(visited[curr]==0){//Visiting for 1st time
            visited[curr]=1;
            for(int nbr: adj[curr]){
                int res = dfs(nbr,adj,visited,longest,colors);
                if(res==INT_MAX)
                    return INT_MAX;
                
                //Iterate for each color for the current nbr and update max_len for each color at current node
                for(int i=0;i<26;++i)
                    longest[i][curr] = max(longest[i][curr],longest[i][nbr]);
            }
            longest[colors[curr]-'a'][curr]++;
            visited[curr]=2;
        }
        return longest[colors[curr]-'a'][curr];
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        for(auto& edge: edges)
            adj[edge[0]].push_back(edge[1]);

        vector<vector<int>> longest(26,vector<int>(n));
        /*
            longest: Table to store the count of each color from a given node
            longest[i][j]=X: There are 'X' number of 'i' color nodes from current node 'j'
        */
        //Perform DFS from each node and maximize color length
        int max_color_length = 0;
        vector<int> visited(n);
        /*
            3-color method is used to detect cycle in directed graph.
            0: Unvisited
            1: Visited & Processing
            2: Visited & Processed
        */
        for(int i=0;i<n;++i){
            int res = dfs(i,adj,visited,longest,colors);
            if(res==INT_MAX)
                return -1;
            max_color_length = max(max_color_length,res);
        }
        return max_color_length;
    }
};