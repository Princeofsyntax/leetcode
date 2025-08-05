class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            bool placed = false;
            for(int j = 0; j < n; j++){
                if(baskets[j] == -1) continue;
                if(baskets[j] >= fruits[i]){
                    placed = true;
                    baskets[j] = -1;
                    break;
                }
            } 
            if(!placed) ans++;
            placed = false;
        }
        return ans;
    }
};