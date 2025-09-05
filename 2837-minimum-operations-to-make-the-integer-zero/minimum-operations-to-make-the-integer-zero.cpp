class Solution {
public:
    bool check(int k, int num1, int num2){
        long long x = (long long)num1 - (long long)k * num2;
        if(x < k || x < 0) return false;
        int min_powers = __builtin_popcountll(x);
        return min_powers <= k;
    }

    int makeTheIntegerZero(int num1, int num2) {
        for(int k=1; k<=60; ++k){
            if(check(k, num1, num2)) return k;
        }
        return -1;
    }
};
