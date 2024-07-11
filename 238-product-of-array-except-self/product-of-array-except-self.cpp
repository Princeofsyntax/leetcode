class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // Fill the left array with the prefix products
        for(int i = 1; i < n; ++i) {
            left[i] = left[i-1] * nums[i-1];
        }

        // Fill the right array with the suffix products
        for(int i = n-2; i >= 0; --i) {
            right[i] = right[i+1] * nums[i+1];
        }

        // Calculate the result by multiplying left and right products
        for(int i = 0; i < n; ++i) {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};