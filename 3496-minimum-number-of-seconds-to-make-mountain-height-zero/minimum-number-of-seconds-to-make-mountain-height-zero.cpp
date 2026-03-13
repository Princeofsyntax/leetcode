class Solution {
public:
    
    bool can(long long T, int mountainHeight, vector<int>& workerTimes){
        long long removed = 0;
        for(int w : workerTimes){
            long long val = (2*T) / w;
            long long x = (sqrt(1 + 4*val) - 1) / 2;        
            removed += x;        
            if(removed >= mountainHeight)
                return true;
        }   
        return false;
    }
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1;
        long long right = 1e18;
        long long ans = right;
        while(left <= right){ 
            long long mid = (left + right) / 2;
            if(can(mid, mountainHeight, workerTimes)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};