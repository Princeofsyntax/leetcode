class Solution {
public:
    double myPow(double x, int N) {
        double ans = 1.00000;
        bool neg = false;
        long long n = N;
        if(n < 0){
            n = -n;
            neg = true;
        }

        while(n){
            if(n%2){
                // odd
                ans = ans*x;
                n = n-1;
            }
            else{
                //even
                x = x*x;
                n = n/2;
            }
        }
        
        if(neg){
            ans = (double)1.00000/(double)ans;
        }
        return ans;
    }
};