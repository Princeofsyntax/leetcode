class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // Calculate the area with the current left and right pointers
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentWater = width * currentHeight;

            // Update maxWater if we found a larger area
            maxWater = max(maxWater, currentWater);

            // Move the pointers
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxWater;

    }
};