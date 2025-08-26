class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonalSq = 0; 
        int maxArea = 0;       

        for (const auto& dim : dimensions) {
            int length = dim[0];
            int width = dim[1];

            int currentDiagonalSq = length * length + width * width;

            if (currentDiagonalSq > maxDiagonalSq) {
                maxDiagonalSq = currentDiagonalSq;
                maxArea = length * width;
            } 
            else if (currentDiagonalSq == maxDiagonalSq) {
                maxArea = max(maxArea, length * width);
            }
        }
        return maxArea;
    }
};