class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0; 
        int maxPrefix = values[0]; // To store the maximum value of values[i] + i seen so far
        for (int j = 1; j < values.size(); ++j) {
            maxScore = max(maxScore, maxPrefix + values[j] - j);
            maxPrefix = max(maxPrefix, values[j] + j);
        }
        return maxScore;
    }
};