class Solution {
public:
    const int MOD = 1e9 + 7;

    long long helper(long long base, long long exp){
        long long ans = 1;
        while(exp > 0){
            if(exp%2 == 1) ans = (ans*base)%MOD;
            base = (base*base)%MOD;
            exp /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long evenMultiple = helper(5, even); 
        long long oddMultiple = helper(4, odd);
        return (evenMultiple * oddMultiple)%MOD;
    }
};