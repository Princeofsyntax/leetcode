class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false;
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        int odd_count = 0;
        for (auto &[key, value] : freq) {
            if (value % 2 != 0) {
                odd_count++;
            }
        }
        return odd_count <= k;
    }
};