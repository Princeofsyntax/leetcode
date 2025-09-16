class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            ans.push_back(num);
            while (ans.size() >= 2) {
                long long last = ans.back();
                ans.pop_back();
                long long second_last = ans.back();
                
                long long common_divisor = gcd(second_last, last);
                
                if (common_divisor == 1) {
                    ans.push_back(last);
                    break;
                } else {
                    ans.back() = lcm(second_last, last);
                }
            }
        }
        return ans;
    }
};