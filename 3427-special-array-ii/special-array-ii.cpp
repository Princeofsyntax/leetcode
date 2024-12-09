class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        vector<int> diff_parity(n - 1, 0);
        for(int i = 0; i < n - 1; ++i){
            diff_parity[i] = (nums[i] % 2) != (nums[i + 1] % 2);
        }
        vector<int> prefix(n, 0);
        for(int i = 1; i < n; ++i){
            prefix[i] = prefix[i - 1] + diff_parity[i - 1];
        }
        vector<bool> answer;
        for(const auto& query : queries){
            int fromi = query[0], toi = query[1];
            if(toi == fromi){
                answer.push_back(true);
            } else{
                int diff_count = prefix[toi] - prefix[fromi];
                answer.push_back(diff_count == (toi - fromi));
            }
        }
        return answer;
    }
};