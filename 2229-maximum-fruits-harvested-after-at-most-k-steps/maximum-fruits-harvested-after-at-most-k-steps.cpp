class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, right = 0;
        int maxi = 0;
        int currSum = 0; 
        
        while (right < n) {
            currSum += fruits[right][1];

            while (left <= right && 
                min(
                    abs(startPos - fruits[left][0]) + (fruits[right][0] - fruits[left][0]),
                    abs(startPos - fruits[right][0]) + (fruits[right][0] - fruits[left][0])
                ) > k) {
                currSum -= fruits[left][1];
                left++;
            }

            maxi = max(maxi, currSum);
            right++;
        }
        return maxi;
    }
};
