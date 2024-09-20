class Solution {
public:
    string shortestPalindrome(string s) {
         string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + "#" + rev_s;
        
        // Build KMP table (longest prefix-suffix table)
        vector<int> lps(new_s.size(), 0);
        
        for (int i = 1; i < new_s.size(); ++i) {
            int j = lps[i - 1];
            while (j > 0 && new_s[i] != new_s[j]) {
                j = lps[j - 1];
            }
            if (new_s[i] == new_s[j]) {
                j++;
            }
            lps[i] = j;
        }
        
     int palin_len = lps[new_s.size() - 1];
        string add_on = rev_s.substr(0, rev_s.size() - palin_len);
        
        return add_on + s;
    }
};