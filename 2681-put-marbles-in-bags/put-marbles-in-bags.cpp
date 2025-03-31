class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        //take pairs just consecutive to the partition
        int n = weights.size();
        vector<long long>helper;
        for(int i = 0; i < n-1; i++){
            helper.push_back((long long)(weights[i] + weights[i+1]));
        }
        sort(helper.begin(), helper.end());
        long long minSum = 0;
        long long maxSum = 0;
        int size = helper.size();
        for(int i = 0; i < k-1; i++){
            maxSum += helper[size-1-i];
            minSum += helper[i];
        }
        //the first and last element is neglected here as when they will be subtracted, they will get cancelled
        return maxSum - minSum;
    }
};