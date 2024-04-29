class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        build(edges);
        vector<int> ans(n);
        vector<int> count(n);
        vector<bool> vis(n, false);
        count_subnode(count, 0, vis);
        vector<bool> vis1(n, false);
        sum = 0;
        helper(0, 0, vis1);
        ans[0] = sum;
        vector<bool> vis2(n, false);
        fill_ans(ans, 0, vis2, count);
        return ans;
    }

private:
    int sum;
    vector<vector<int>> graph;

    void build(vector<vector<int>>& edges) {
        for (int i = 0; i < graph.size(); i++) {
            graph[i] = vector<int>();
        }
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }

    void fill_ans(vector<int>& ans, int curr, vector<bool>& vis, vector<int>& count) {
        vis[curr] = true;
        for (int i : graph[curr]) {
            if (!vis[i]) {
                ans[i] = ans[curr] + graph.size() - 2 * count[i];
                fill_ans(ans, i, vis, count);
            }
        }
    }

    void helper(int curr, int s, vector<bool>& vis) {
        vis[curr] = true;
        for (int i = 0; i < graph[curr].size(); i++) {
            if (!vis[graph[curr][i]])
                helper(graph[curr][i], s + 1, vis);
        }
        sum += s;
    }

    int count_subnode(vector<int>& count, int curr, vector<bool>& vis) {
        int c = 1;
        vis[curr] = true;
        for (int i : graph[curr]) {
            if (!vis[i]) {
                c += count_subnode(count, i, vis);
            }
        }
        count[curr] = c;
        return c;
    }
};