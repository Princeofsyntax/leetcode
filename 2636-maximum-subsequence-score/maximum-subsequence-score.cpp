class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
         int n = nums1.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums2[i], nums1[i]};
        }

        // Sort pairs by nums2 in descending order
        sort(pairs.rbegin(), pairs.rend());

        // Min-heap to maintain the largest sum of k elements from nums1
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, maxScore = 0;

        for (int i = 0; i < n; ++i) {
            int nums2Val = pairs[i].first;
            int nums1Val = pairs[i].second;

            // Add current nums1 value to the heap and to the sum
            minHeap.push(nums1Val);
            sum += nums1Val;

            // If heap size exceeds k, remove the smallest element
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            // If heap size is k, calculate the score
            if (minHeap.size() == k) {
                maxScore = max(maxScore, sum * nums2Val);
            }
        }

        return maxScore;
        
    }
};