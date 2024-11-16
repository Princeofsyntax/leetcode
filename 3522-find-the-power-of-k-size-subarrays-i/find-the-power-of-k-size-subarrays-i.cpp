class Solution {
public:
    bool isConsSort(vector<int>&arr, int j, int k){
        for(int i = j+1; i < j+k; i++){
            if(arr[i] != arr[i-1]+1){
                return false;
            }
        }
        return true;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;

        for(int i = 0; i <= nums.size() - k; i++){
           if(isConsSort(nums, i, k)){
                 ans.push_back(*max_element(nums.begin() + i, nums.begin() +i + k));
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};