class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        for (int num : nums1) {
            xor1 ^= num;
        }
        for (int num : nums2) {
            xor2 ^= num;
        }
        int ans = 0;
        //If nums1.size() is odd, each element in nums2 contributes to the result.
        if (nums1.size() % 2 != 0) {
            ans ^= xor2;
        }
        //If nums2.size() is odd, each element in nums1 contributes to the result.
        if (nums2.size() % 2 != 0) {
            ans ^= xor1;
        }
        return ans;
    }
};
