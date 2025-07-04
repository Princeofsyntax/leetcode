class Solution {
public:
    char shiftChar(char c, int shiftCount) {
        return 'a' + (c - 'a' + shiftCount) % 26;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        int shiftCount = 0;

        while (n > 0) {
            n--;

            //safely calculate 2^n using left shift only if n < 63
            long long len = (n < 63) ? (1LL << n) : LLONG_MAX;

            if (k > len) {
                k -= len;
                if (operations[n] == 1)
                    shiftCount++;
            }
            // else stay in first half
        }

        return shiftChar('a', shiftCount);
    }
};
