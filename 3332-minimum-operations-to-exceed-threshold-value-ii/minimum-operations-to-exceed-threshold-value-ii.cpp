class Solution {
public:
    int minOperations(vector<int>& nums, int k){
       priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
        }
        int operations = 0;
        while (minHeap.size() >= 2 && minHeap.top() < k) {
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();
            long long newElement = min(x, y) * 2 + max(x, y);
            minHeap.push(newElement);
            operations++;
        }
        //if the smallest element is still < k, we need to perform additional operations
        while (minHeap.size() >= 2 && minHeap.top() < k) {
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();
            long long newElement = min(x, y) * 2 + max(x, y);
            minHeap.push(newElement);
            operations++;
        }
        return operations;
    }
};