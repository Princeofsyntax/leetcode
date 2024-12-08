class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; 
        });
        map<int, int> maxValue;
        int maxSoFar = 0;
        int result = 0;
        for (const auto& event : events) {
            int start = event[0], end = event[1], value = event[2];
            auto it = maxValue.lower_bound(start); // First event that ends >= start
            if (it != maxValue.begin()) {
                --it; // Move to the last event that ends before start
                result = max(result, it->second + value);
            }
            result = max(result, value);
            maxSoFar = max(maxSoFar, value);
            maxValue[end] = maxSoFar;
        }
        return result;
    }
};