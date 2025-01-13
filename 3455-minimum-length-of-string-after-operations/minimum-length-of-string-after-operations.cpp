class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char, int> freqCount;
        for (const auto& c : s) {
            freqCount[c]++;
            // handle the case here only that if count become
            // greater than 2 then they will sure from pair
            // left and right --> subtract 2 from size
            if (freqCount[c] == 3) {
                freqCount[c] = 1; // reset
                n -= 2;
            }
        }

        return n;
    }
};