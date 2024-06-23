class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minDeque;
        deque<int> maxDeque;
        int left = 0;
        int maxLength = 0;
            
        for (int right = 0; right < nums.size(); ++right) {
                // Maintain the max deque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                    maxDeque.pop_back();
                }
            maxDeque.push_back(right);
                
                // Maintain the min deque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                    minDeque.pop_back();
                }
            minDeque.push_back(right);
                
                // Ensure the window is valid
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                    left++;
                    // Remove indices out of the new window
                    if (maxDeque.front() < left) {
                        maxDeque.pop_front();
                    }
                    if (minDeque.front() < left) {
                        minDeque.pop_front();
                    }
            }
                
                // Update the maximum length of the window
                maxLength = max(maxLength, right - left + 1);
        }
            
        return maxLength;
    }
};