class Solution {
public:
    void helper(long long &zero, long long &minSum, vector<int>& nums){
        for(const auto& num: nums){
            if(num == 0){
                minSum++;
                zero++;
            }
            else{
                minSum += num;
            }
        }
    }

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        long long zero1 = 0;
        long long minSum1 = 0;
        helper(zero1, minSum1, nums1);
        long long zero2 = 0;
        long long minSum2 = 0;
        helper(zero2, minSum2, nums2);
        if(((minSum1 < minSum2) && zero1 == 0) || ((minSum2 < minSum1) && zero2 == 0))return -1;
        return max(minSum1, minSum2);
    }
};