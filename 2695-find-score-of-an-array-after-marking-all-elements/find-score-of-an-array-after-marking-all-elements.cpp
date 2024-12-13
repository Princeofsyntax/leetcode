class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (int i = 0; i < n; ++i) {
            minHeap.push({nums[i], i});
        }
        vector<bool> marked(n, false); 
        while (!minHeap.empty()) {
            auto [value, index] = minHeap.top();
            minHeap.pop();
            if (marked[index]) continue;
            score += value;
            marked[index] = true;
            if (index > 0) marked[index - 1] = true;
            if (index < n - 1) marked[index + 1] = true;
        }
        return score;
    }
};