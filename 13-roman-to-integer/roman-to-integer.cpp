class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int result = 0;
        unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        for (int i = 0; i < n; i++) {
        if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]];
        } else {
            result += roman[s[i]];
        }
     }

    return result;
    }
};