class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        vector<int>ans(k);
        if(k == 0) return 0;

        for(int i = 0; i < k; i++){
            ans[i] = happiness[i];
        }
        if(k == 1) return ans[0];

        long long sum = 0;
        int decreseBy = 0;
        for(int i = 0; i < k; i++){
            sum += max(0, happiness[i] - decreseBy);
            ++decreseBy;
        }

        return sum;
    }
};