class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // If the middle element is greater than the element to its right, 
                // then the peak must be in the left half including the middle element
                right = mid;
            } else {
                // If the middle element is less than or equal to the element to its right,
                // then the peak must be in the right half excluding the middle element
                left = mid + 1;
            }
        }

        // When left == right, we have found a peak element
        return left;
    }
};