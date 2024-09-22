class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(b.empty()) return 0;
        string repeatedA = a;
        int repeatCount = 1;

        while (repeatedA.length() < b.length()) {
            repeatedA += a;
            repeatCount++;
         }

        if (repeatedA.find(b) != string::npos) {
            return repeatCount;
         }

        repeatedA += a;
        repeatCount++;

        if (repeatedA.find(b) != string::npos) {
            return repeatCount;
        }

        return -1;

    }
};