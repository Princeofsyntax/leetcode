class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        if (len1 > len2) return false;
        if (str2.substr(0, len1) != str1) return false;
        if (str2.substr(len2 - len1, len1) != str1) return false;
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++count;
                }
            }
        }
        return count;
    }
};