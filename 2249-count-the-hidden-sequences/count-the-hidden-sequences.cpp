class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long curr = 0;
        long long minValue = 0;
        long long maxValue = 0;
        //we will solve using range, the solution will lie between range given(upper - lower) and acutal range difference (max-min)
        for (const auto& val : differences) {
            curr += val;
            minValue = min(minValue, curr);
            maxValue = max(maxValue, curr);
        }
        long long totalRange = (long long)upper - lower;
        long long rangeRequired = maxValue - minValue;
        long long ans = totalRange - rangeRequired + 1;

        return ans > 0 ? (int)ans : 0;
    }
};