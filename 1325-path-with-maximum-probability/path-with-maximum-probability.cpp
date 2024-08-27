class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<vector<pair<int, double>>>adjList(n);
        for(int i = 0; i < edges.size(); i++){
            int curr_node = edges[i][0];
            int next_node = edges[i][1];
            double prob = succProb[i];
            adjList[curr_node].emplace_back(next_node, prob);
            adjList[next_node].emplace_back(curr_node, prob);
        }
         
        // Probability to reach a particular node ( prob, node )
        priority_queue<pair<double, int>>pq;
        pq.emplace(1.0, start_node);

        vector<double>maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        while(!pq.empty()){
            int curr_node = pq.top().second;
            double curr_prob = pq.top().first;
            pq.pop();

            if(curr_node == end_node) return curr_prob;

            for(auto& neighbour : adjList[curr_node]){
                int next_node = neighbour.first;
                double next_prob = neighbour.second;

                if(maxProb[next_node] < curr_prob * next_prob){
                    maxProb[next_node] = curr_prob * next_prob;
                    pq.emplace(maxProb[next_node], next_node);
                }
            }
        }

        return 0.0;
    }
};