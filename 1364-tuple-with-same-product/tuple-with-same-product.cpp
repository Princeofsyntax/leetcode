class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i =0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(const auto& m :mp){
            ans += (m.second*(m.second-1))/2;
        }
        return ans*8;
    }
};