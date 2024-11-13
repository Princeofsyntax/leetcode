class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        // since we have to only count pairs, so we can sort
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n-1; i++){
            int left = i+1;
            int right = n-1;
            while(left <= right){
                int mid = left + (right-left)/2;
                if(nums[i]+nums[mid] >= lower){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            int start = left;
            right = n-1;
            
            while(left <= right){
                int mid = left + (right-left)/2;
                if(nums[i]+nums[mid] <= upper){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            int end = right;

            if(start <= end){
                ans += (end-start+1);
            }

        }
        return ans;
    }
};