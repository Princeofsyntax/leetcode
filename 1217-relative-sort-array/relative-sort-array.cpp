class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;

        // Count the frequency of each element in arr1
        for(auto item : arr1){
            mp[item]++;
        }

        vector<int> ans;

        // Add elements from arr2 to ans, in order, and as many times as they appear in arr1
        for(auto item : arr2){
            while(mp[item] > 0){
                ans.push_back(item);
                mp[item]--;
            }
        }

        // Sort arr1 to handle elements not in arr2
        sort(arr1.begin(), arr1.end());

        // Add the remaining elements from arr1 to ans
        for(auto item : arr1){
            if(mp[item] > 0){
                while(mp[item] > 0){
                    ans.push_back(item);
                    mp[item]--;
                }
            }
        }

        return ans;
    }
};
