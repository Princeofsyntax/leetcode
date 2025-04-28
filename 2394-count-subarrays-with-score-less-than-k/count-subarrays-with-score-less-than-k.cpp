class Solution {
    using ll = long long;
public:
    long long countSubarrays(const vector<int>& nums, long long k) {
        ll n = nums.size();
        ll left = 0, right = 0;   //window is [left, right)
        ll sum = 0;               //sum of nums[left..right-1]
        ll count = 0;

        while (left < n) {
            //find largest valid window
            while (right<n and (sum+nums[right])*(right-left+1) < k)
                sum += nums[right++];

            count += right - left; //all subarrays starting at `left` and ending before `right` are valid

            //slide the window forward by removing nums[left]
            if (right == left)//if we couldn’t even include nums[left], move both pointers past it
                right++;
            else 
                sum -= nums[left];
            
            left++;
        }
        return count;
    }
};