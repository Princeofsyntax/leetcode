class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> unique_elements(nums.begin(),nums.end());
        int unique_count = unique_elements.size();

        int left = 0;
        int right = 0;
        int n = nums.size();
        unordered_map<int,int> freq;
        int complete_subarrays = 0;

        while(left<n){
            while(right<n and freq.size()<unique_count){
                freq[nums[right]]++;
                right++;
            }
            if(freq.size()<unique_count)
                break;
            
            complete_subarrays += n-right+1;
            //Remove left
            freq[nums[left]]--;
            if(freq[nums[left]]==0)
                freq.erase(nums[left]);
            left++;
        }
        return complete_subarrays;
    }
};