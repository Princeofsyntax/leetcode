class Solution {
public:

    typedef pair<int, int> ProfitCapitalPair;

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // A min-heap that stores pairs of capital requirements and profits
        // Such that the project with the least capital requirement is on top.
        priority_queue<ProfitCapitalPair, vector<ProfitCapitalPair>, std::greater<ProfitCapitalPair>> minCapitalHeap;

        int numProjects = profits.size();
        for (int i = 0; i < numProjects; ++i) {
            minCapitalHeap.push({capital[i], profits[i]});
        }

        // A max-heap to store profits of projects we can afford to invest in,
        // so we can always choose the most profitable one next.
        priority_queue<int> maxProfitHeap;

        // Loop to perform up to 'k' investments.
        while (k--) {
            // Move all projects we can afford (with current capital 'w') to a max-heap.
            // This heap will help us to quickly select the next most profitable project.
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= w) {
                maxProfitHeap.push(minCapitalHeap.top().second);
                minCapitalHeap.pop();
            }

            // If we cannot afford any project, break out of the loop.
            if (maxProfitHeap.empty()) {
                break;
            }

            // Pick the most profitable project and increase our capital.
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        // After completing 'k' or the maximum number of profitable investments,
        // 'w' is our maximized capital.
        return w;
    }
};