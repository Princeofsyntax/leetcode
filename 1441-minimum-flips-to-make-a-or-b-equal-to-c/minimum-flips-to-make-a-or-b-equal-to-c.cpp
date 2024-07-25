class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        for (int i = 0; i < 32; ++i) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;

            if ((bitA | bitB) != bitC) {
                if (bitC == 1) {
                    // If bitC is 1, but bitA | bitB is 0, we need one flip to make either bitA or bitB to 1
                    flips++;
                } else {
                    // If bitC is 0, but bitA | bitB is 1, we need flips for both bitA and bitB if they are 1
                    flips += bitA + bitB;
                }
            }
        }

        return flips;
    }
};