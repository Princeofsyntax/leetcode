class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int result = 0;
        bool hasCentralPalindrome = false;

        for (auto& word : words) {
            freq[word]++;
        }

        for (auto& [word, count] : freq) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word != rev) {
                if (freq.find(rev) != freq.end()) {
                    int pairs = min(count, freq[rev]);
                    result += pairs * 4;
                    freq[word] -= pairs;
                    freq[rev] -= pairs;
                }
            } else {
                // Palindromic word like "gg", "cc", etc.
                int pairs = count / 2;
                result += pairs * 4;
                freq[word] -= pairs * 2;

                if (freq[word] > 0) {
                    hasCentralPalindrome = true;
                }
            }
        }

        if (hasCentralPalindrome) result += 2;

        return result;
    }
};