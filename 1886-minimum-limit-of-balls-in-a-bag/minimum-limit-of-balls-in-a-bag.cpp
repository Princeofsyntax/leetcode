class Solution {
public:
    bool canDivide(vector<int>& nums, int maxOperations, int maxPenalty) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > maxPenalty) {
                operations += (balls - 1) / maxPenalty;
            }
            if (operations > maxOperations) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, maxOperations, mid)) {
                result = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};