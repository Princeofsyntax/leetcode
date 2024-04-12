class Solution {
private:
    vector<int> topoSortBFS(int n, unordered_map<int, list<int>>& adjList)
    {
        vector<int> ans;
        queue<int> q;
        unordered_map<int, int> indegree;

        // indegree calculation
        for (auto i : adjList)
        {
            int src = i.first;
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        // Now put all nodes inside queue which has indegree 0
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // bfs logic
        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();
            ans.push_back(fNode);

            // find neighbour and subtract 1 in indegree as we have to remove the node used
            for (auto nbr : adjList[fNode])
            {
                indegree[nbr]--;
                // check if indegree becomes zero
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        //check
        if(ans.size() == n){
            //valid topoSort
            return ans;
        }
        else{
            return {};
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //Code is almost same as leetcode 207
        unordered_map<int, list<int>>adjList;
        
        for(auto tasks : prerequisites)
        {
            int u = tasks[0];
            int v = tasks[1];
            adjList[v].push_back(u);
        }
        vector<int>ans = topoSortBFS(numCourses,adjList); 
        return ans;
    }
};