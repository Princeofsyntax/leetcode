class Solution {
public:
    int jump(vector<int>& nums) {
        int numJumps = 0;           
        int currentMaxReach = 0;    
        int lastMaxReach = 0;       
      
        for (int i = 0; i < nums.size() - 1; ++i) {
           currentMaxReach = max(currentMaxReach, i + nums[i]);
          
        if (lastMaxReach == i) {
                numJumps++;
                lastMaxReach = currentMaxReach;  // Update the max reach for the new jump.
            }
        }
      
        return numJumps;  
    }
  
};