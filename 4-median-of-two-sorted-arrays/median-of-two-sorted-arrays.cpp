class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && !nums2.empty()){
            int size = nums2.size() / 2;
            if(nums2.size() % 2 == 0){
                return (nums2[size - 1] + nums2[size]) / 2.0;
            } else{
                return nums2[size];
            }
        }
        if(nums2.empty() && !nums1.empty()){
            int size = nums1.size() / 2;
            if(nums1.size() % 2 == 0){
                return (nums1[size - 1] + nums1[size]) / 2.0;
            } else{
                return nums1[size];
            }
        }
        if(nums2.empty() && nums1.empty()){
            return 0.0;
        }
        
        vector<int> merged;
        int index1 = 0;
        int index2 = 0;

        while(index1 < nums1.size() && index2 < nums2.size()){
            if(nums1[index1] <= nums2[index2]){
                merged.push_back(nums1[index1]);
                index1++;
            } else{
                merged.push_back(nums2[index2]);
                index2++;
            }
        }

        while(index1 < nums1.size()){
            merged.push_back(nums1[index1]);
            index1++;
        }

        while(index2 < nums2.size()){
            merged.push_back(nums2[index2]);
            index2++;
        }

        int size = merged.size();
        if(size % 2 == 0){
            return (merged[size/2 - 1] + merged[size/2]) / 2.0;
        } else{
            return merged[size/2];
        }
    }
};
