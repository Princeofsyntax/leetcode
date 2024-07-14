class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int ans = 0;
       int sum = 0;
       for(auto g : gain){
          sum = sum+g;
          ans = max(ans,sum);
       }
       return ans;
    }
};