class Solution {
private:
    bool topoSortBFS(int n, unordered_map<int, list<int>>& adjList)
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
            return true;
        }
        else{
            return false;
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //HINT1-here dependency exist of taking course ( as previous course need to be taken ) so we can solve via topological sort--> graph
        //HINT2-if cyclic dependency is present then courses cannot be completed OR no topological sort present ( as cycle is present)
        unordered_map<int, list<int>>adjList;
        //create adjacency list ( for graph)
        for(auto tasks : prerequisites)
        {
            int u = tasks[0];
            int v = tasks[1]; //edge is from v --> u as dependency flow is in this direction
            adjList[v].push_back(u);
        }
        bool ans = topoSortBFS(numCourses,adjList); //if topoSort is possible then courses can be finished else not
        return ans;
    }
};