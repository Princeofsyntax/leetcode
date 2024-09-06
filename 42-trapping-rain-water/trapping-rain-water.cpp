class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int l_max = 0, r_max = 0;

        int l = 0, r = height.size()-1;
        while(l < r){
            if(height[l] <= height[r]){
                if(l_max > height[l]){
                    total += (l_max - height[l]);
                }
                else{
                    l_max = height[l];
                }
                l++;
            }
            else{
                if(r_max > height[r]){
                    total += (r_max - height[r]);
                }
                else{
                    r_max = height[r];
                }
                r--;
            }
        }
        return total;
    }
};