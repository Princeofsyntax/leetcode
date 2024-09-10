class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st(arr.begin(), arr.end());
        unordered_map<int,int>mp;
        int count = 1;

        for(const auto& s : st){
            mp[s] = count;
            count++;
        }

        for( auto& a : arr){
            a = mp[a];
        }

        return arr;
    }
};