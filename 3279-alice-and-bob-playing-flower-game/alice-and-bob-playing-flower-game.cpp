class Solution {
public:
    long long flowerGame(int n, int m) {
        int even1 = n / 2;
        int odd1 = n - even1;
        int even2 = m / 2;
        int odd2 = m - even2;

        return ((long long)even1 * odd2) + ((long long)even2 * odd1);
    }
};