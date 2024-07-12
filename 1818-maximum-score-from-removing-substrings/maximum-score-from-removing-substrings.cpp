class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (s.size() < 2) return 0;

        int score = 0;

        // Helper function to remove all instances of the target substring
        // and accumulate the points.
        auto removeSubstr = [&](string &s, string target, int points) {
            stack<char> st;
            for (char ch : s) {
                if (!st.empty() && st.top() == target[0] && ch == target[1]) {
                    st.pop();
                    score += points;
                } else {
                    st.push(ch);
                }
            }

            string remaining;
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            return remaining;
        };

        // First, prioritize the higher points operation
        if (x > y) {
            s = removeSubstr(s, "ab", x);
            s = removeSubstr(s, "ba", y);
        } else {
            s = removeSubstr(s, "ba", y);
            s = removeSubstr(s, "ab", x);
        }

        return score;
    }
};