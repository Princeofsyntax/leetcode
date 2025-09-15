class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> check(brokenLetters.begin(), brokenLetters.end());
        int ans = 0;
        int n = text.length();
        for (int i = 0; i < n; i++) {
            bool is_typeable = true;
            int word_end = i;
            while (word_end < n && text[word_end] != ' ') {
                if (check.count(text[word_end])) {
                    is_typeable = false;
                }
                word_end++;
            }
            if (is_typeable) {
                ans++;
            }
            i = word_end;
        }
        return ans;
    }
};