class Solution {
public:
    bool canPlaceBall(vector<int>& position, int minDistance, int m){
        int prevPosition = position[0];

        int count = 1;

        for(int i = 0; i< position.size(); i++){
            int currPosition = position[i];

            if(currPosition - prevPosition >= minDistance){
                prevPosition = currPosition;
                count++;

            }
        }
        return count >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        // Apply binary search to have a feasible solution
        int left = 1; // min force
        int right = position.back(); // max posible force

        while(left < right){
            int mid = (left + right + 1) >> 1;
            if(canPlaceBall(position, mid, m)){
                left = mid;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};