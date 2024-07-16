class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
         
        unordered_set<int>first(nums1.begin(), nums1.end());
        unordered_set<int>second(nums2.begin(), nums2.end());
        
        vector<vector<int>>ans(2);

        for (const auto &num : first) {
            if (second.find(num) == second.end()) {
                ans[0].push_back(num);
            }
        }
        
        for (const auto &num : second) {
            if (first.find(num) == first.end()) {
                ans[1].push_back(num);
            }
        }

        return ans;
    }
};