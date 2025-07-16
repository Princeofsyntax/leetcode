class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0;

        //count even and odd numbers with parity 0
        for (int num : nums) {
            if (num % 2 == 0) even++;
            else odd++;
        }

        //alternating parity subsequence even+odd element to get parity 1
        int altLen = 0;
        int prev = -1;
        for (int num : nums) {
            if (prev == -1 || (num % 2 != prev % 2)) {
                altLen++;
                prev = num;
            }
        }

        return max({altLen, even, odd});
    }
};