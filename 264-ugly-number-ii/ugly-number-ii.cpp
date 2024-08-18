class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;

        priority_queue<long, vector<long>, greater<long>>minHeap;
        unordered_set<long>seen;

        long currentUgly = 1;
        minHeap.push(currentUgly);
        seen.insert(currentUgly);
        vector<int>factors{2,3,5};

        for(int i = 0; i < n; i++){
            currentUgly = minHeap.top();
            minHeap.pop();

            for(const auto&factor : factors){
                long newUgly = factor*currentUgly;
                if(seen.find(newUgly) == seen.end()){
                    //didn't found
                    minHeap.push(newUgly);
                    seen.insert(newUgly);
                }
            }
        }

        return currentUgly;

    }
};