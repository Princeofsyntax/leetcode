class FindSumPairs {
public:
    vector<int> nums1r;
    vector<int> nums2r;
    unordered_map<int, int> mp1; 
    unordered_map<int, int> mp2;  

    FindSumPairs(vector<int>& nums1, vector<int>& nums2){
        nums1r = nums1;
        nums2r = nums2;
        for (const auto& num1 : nums1r) mp1[num1]++;
        for (const auto& num2 : nums2r) mp2[num2]++;
    }

    void add(int index, int val){
        int oldVal = nums2r[index];
        mp2[oldVal]--;

        nums2r[index] += val;

        mp2[nums2r[index]]++;
    }

    int count(int tot){
        int result = 0;
        for (const auto& [num1, freq1] : mp1){
            int target = tot - num1;
            if (mp2.find(target) != mp2.end()){
                result += freq1 * mp2[target];
            }
        }
        return result;
    }
};