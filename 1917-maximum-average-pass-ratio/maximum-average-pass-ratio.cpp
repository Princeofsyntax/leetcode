class Solution {
public:
    double passRatioGain(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max-heap to store the classes with the highest gain at the top
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& c : classes) {
            int pass = c[0], total = c[1];
            maxHeap.push({passRatioGain(pass, total), {pass, total}});
        }
        while (extraStudents > 0) {
            auto top = maxHeap.top();
            maxHeap.pop();
            double gain = top.first;
            int pass = top.second.first;
            int total = top.second.second;
            pass++;
            total++;
            extraStudents--;
            maxHeap.push({passRatioGain(pass, total), {pass, total}});
        }
        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            int pass = top.second.first;
            int total = top.second.second;
            totalRatio += (double)pass / total;
        }
        return totalRatio / classes.size();
    }
};