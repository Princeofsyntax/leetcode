class Solution {
public:
    int removePair(string &s, char first, char second, int points) {
        int total = 0;
        string temp;
        for (char c : s) {
            if (!temp.empty() && temp.back() == first && c == second) {
                temp.pop_back();
                total += points;
            } else {
                temp.push_back(c);
            }
        }
        s = temp;
        return total;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;
        if (x >= y) {
            total += removePair(s, 'a', 'b', x);
            total += removePair(s, 'b', 'a', y);
        } else {
            total += removePair(s, 'b', 'a', y);
            total += removePair(s, 'a', 'b', x);
        }
        return total;
    }
};