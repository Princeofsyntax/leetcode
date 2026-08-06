class Solution {
public:
    int helper(int n, int t){
        int ans = 1;
        while(n > 0){
            int digit = n % 10;
            ans *= digit;
            n /= 10;
            if(ans == 0)break;
        }
        return ans % t == 0;
    }

    int smallestNumber(int n, int t) {
        for(int i = n; ; i++){
            if(helper(i,t)){
                return i;
            }
        }
    }
};