class Solution {
public:
    int getMappedValue(int num, const vector<int>& mapping) {
        string numStr = to_string(num);
        for (char& ch : numStr) {
            ch = '0' + mapping[ch - '0'];
        }
        return stoi(numStr);
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mappedNums;
        for (int num : nums) {
            int mappedValue = getMappedValue(num, mapping);
            mappedNums.push_back({mappedValue, num});
        }
        
        stable_sort(mappedNums.begin(), mappedNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        
        vector<int> sortedNums;
        for (const auto& p : mappedNums) {
            sortedNums.push_back(p.second);
        }
        
        return sortedNums;
    }
};