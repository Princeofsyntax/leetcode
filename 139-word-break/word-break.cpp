class Solution {
public:
    unordered_map<int, bool> memo;

    bool canBreak(int start, string &s, unordered_set<string> &wordSet) {
        if (start == s.size()) return true;

        if (memo.find(start) != memo.end()) return memo[start];

        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (wordSet.find(substring) != wordSet.end() && canBreak(end, s, wordSet)) {
                return memo[start] = true;
            }
        }
        
        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return canBreak(0, s, wordSet);
    }
};