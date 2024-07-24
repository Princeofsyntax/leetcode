class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(const auto& num : arr){
            mp[num]++;
        }
        
        set<int> values;
        for (const auto& pair : mp) {
        if (values.find(pair.second) != values.end()) {
            return false;
           }
        values.insert(pair.second);
        }
    return true;
    }
};