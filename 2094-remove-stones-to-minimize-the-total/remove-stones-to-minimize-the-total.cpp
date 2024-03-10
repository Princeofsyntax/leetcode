class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        //if we apply the given operation on maximum stone pile than minimum answer can be acheived
        //use maxHeap
        priority_queue<int>maxHeap;

        for(int i=0; i<piles.size(); i++){
          maxHeap.push(piles[i]);
        }

        while(k--){
          int maxElement = maxHeap.top();
          maxHeap.pop();
          maxElement = maxElement - floor(maxElement/2);
          maxHeap.push(maxElement);
        }
        int sum = 0;
        while(!maxHeap.empty()){
            int temp = maxHeap.top();
            maxHeap.pop();
            sum += temp;
        }
        return sum;
    }
};