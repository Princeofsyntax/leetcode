class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0) return s;

        vector<string> helper;
        string toAdd = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                toAdd.push_back(s[i]);
            } else if (s[i] == ' ' && toAdd.size() > 0) {
                helper.push_back(toAdd);
                toAdd = "";
            }
        }

        // Add the last word if it exists
        if (toAdd.size() > 0) {
            helper.push_back(toAdd);
        }

        string ans = "";
        for (int i = helper.size() - 1; i >= 0; i--) {
            ans += helper[i];
            if (i > 0) {
                ans += " ";
            }
        }

        return ans;
    }
};