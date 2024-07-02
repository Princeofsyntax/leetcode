class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0) return {};

        unordered_map<int, int>mp1;
        unordered_map<int, int>mp2;

        for(const auto& num : nums1){
            mp1[num]++;
        }
        for(const auto& num : nums2){
            mp2[num]++;
        }

        vector<int>ans;

        for(const auto& pair : mp1){
            if(mp2.find(pair.first) != mp2.end()){
                int count = 0;
                int second = mp2[pair.first];
                int first = mp1[pair.first];
                count = min(first,second);
                while(count > 0){
                    ans.push_back(pair.first);
                    count--;
                }
            }
        }

        return ans;
    }
};