class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (int a : answers) freq[a]++;
        int res = 0;
        for (auto& [val, count] : freq) {
            int groupSize = val + 1;
            // ceil(count / groupSize) * groupSize
            res += ((count + groupSize - 1) / groupSize) * groupSize;
        }
        return res;
    }
};