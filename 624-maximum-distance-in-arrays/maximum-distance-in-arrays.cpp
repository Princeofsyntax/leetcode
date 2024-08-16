class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();
        int result = 0;

        for (int i = 1; i < arrays.size(); i++) {
            // Compare the current array's first and last elements with global min and max
            result = max(result, max(abs(arrays[i].back() - minVal), abs(maxVal - arrays[i].front())));
            
            // Update the global min and max for future iterations
            minVal = min(minVal, arrays[i].front());
            maxVal = max(maxVal, arrays[i].back());
        }

        return result;
    }
};
