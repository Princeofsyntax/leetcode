class Solution {
public:
    int countPrimes(int n) {
         if(n == 0) return 0;

        vector<bool> prime(n, true); //size of n and all havine value true
        prime[0] = prime[1] = false; //as these numbers are non prime

        int ans = 0;
        
        for (int i = 2; i < n; i++)
        {
            if(prime[i]){
                ans++;

                int j = i*2; //takes next number multiple of itself to start marking false
                while (j < n)
                {
                    prime[j] = false;
                    j += i;
                }
                
            }
        }
        return ans;
        }
};