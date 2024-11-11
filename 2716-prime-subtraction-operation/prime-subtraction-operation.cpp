class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        for (int num = 2; num <= 1000; ++num) {
            bool isPrime = true;
            for (int prime : primes) {
                if (num % prime == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                primes.push_back(num);
            }
        }

        int n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            int primeIndex = upper_bound(primes.begin(), primes.end(), nums[i] - nums[i + 1]) - primes.begin();

            if (primeIndex == primes.size() || primes[primeIndex] >= nums[i]) {
                return false;
            }
            
            nums[i] -= primes[primeIndex];
        }
        return true;
    }
};
