class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       // Helper function to determine if Koko can eat all bananas at speed k within h hours
        auto canFinish = [&](int k) -> bool {
            int hours = 0;
            for (int pile : piles) {
                hours += (pile + k - 1) / k;  // Equivalent to ceil(pile / k)
            }
            return hours <= h;
        };
        
        // Binary search to find the minimum eating speed
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};