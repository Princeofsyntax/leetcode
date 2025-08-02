class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp1, mp2, total;
        for(const auto& b : basket1) mp1[b]++;
        for(const auto& b : basket2) mp2[b]++;
        for(const auto& [k, v] : mp1) total[k] += v;
        for(const auto& [k, v] : mp2) total[k] += v;
        for(const auto& [k, v] : total) if(v%2) return -1;

        int minFruit = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        vector<int>extra1;
        vector<int>extra2;
        for(const auto& [k, v] : total){
            int diff = mp1[k] -( total[k]/2);
            if(diff > 0) extra1.insert(extra1.end(), diff, k); // (position, how many times, the value to be pushed)
            if(diff < 0) extra2.insert(extra2.end(), -diff, k);
        }
        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());
        long long ans = 0;
        int n = extra1.size();
        for(int i = 0; i < n; i++){
            int a = extra1[i], b = extra2[i];
            // best choice is min(min(a, b), 2*minFruit) , 2*minFruit is used as intermediate to get used for double swap to minimise the cost
            ans += min((long long)min(a, b), 2LL * minFruit);
        }
        return ans;
    }
};