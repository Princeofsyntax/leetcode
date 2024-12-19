class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxVal = 0, chunks = 0;
        for (int i = 0; i < arr.size(); ++i) {
            maxVal = max(maxVal, arr[i]);
            if (maxVal == i) {
                chunks++;
            }
        }
        return chunks;
    }
};