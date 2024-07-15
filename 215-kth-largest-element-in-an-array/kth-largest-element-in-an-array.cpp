class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        priority_queue<int> maxHeap(nums.begin(), nums.end());


        for(int i = 1; i < k; i++) {
            maxHeap.pop();
        }

        return maxHeap.top();
    }
};