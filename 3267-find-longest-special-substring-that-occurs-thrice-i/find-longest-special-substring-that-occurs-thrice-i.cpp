class Solution {
public:
    bool isSpecial(string s) {
        char firstChar = s[0];
        for (char c : s) {
            if (c != firstChar) {
                return false; 
            }
        }
        return true; 
    }
    int maximumLength(string s) {
        int n = s.length();
        for (int length = n - 2; length >= 1; length--) {
            unordered_map<string, int> substringCount;
            for (int i = 0; i + length <= n; i++) {
                string substring = s.substr(i, length);
                if (isSpecial(substring)) {
                    substringCount[substring]++;
                }
            }
            for (auto entry : substringCount) {
                if (entry.second >= 3) {
                    return length; 
                }
            }
        }
        return -1;
    }
};