class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        //first sort the array in descending order
        sort(happiness.begin(), happiness.end(), greater<int>());

        vector<int>ans(k);
        if(k == 0) return 0;

        for(int i = 0; i < k; i++){
            ans[i] = happiness[i];
        }
        if(k == 1) return ans[0];

        long long sum = 0;
        int decremented = 0;
        for(int i = 0; i < k; i++){
            sum += max(0, happiness[i] - decremented);
            ++decremented;
        }

        return sum;
    }
};