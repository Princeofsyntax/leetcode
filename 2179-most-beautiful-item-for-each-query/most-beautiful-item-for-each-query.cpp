class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> priceBeauty;
        int maxBeauty = 0;
        for (auto& item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            priceBeauty.push_back({item[0], maxBeauty});
        }
        vector<int> result;
        for (int q : queries) {
            auto it = upper_bound(priceBeauty.begin(), priceBeauty.end(), make_pair(q, INT_MAX));
            if (it == priceBeauty.begin()) {
                result.push_back(0);
            } else {
                result.push_back(prev(it)->second);
            }
        }
        return result;
    }
};