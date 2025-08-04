class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n==1)return 1;
        int maxi = 1, currMax = 1;
        int last = fruits[0] , curr = -1;
        for(int i = 1; i < n; i++){
            if(fruits[i] != last && curr == -1) curr = fruits[i];
            else if(fruits[i] != last && fruits[i] != curr){
                int j = i-1;
                while( j >= 0 && fruits[j] == fruits[i-1])j--;
                currMax = i-j-1;
                last = fruits[i-1];
                curr = fruits[i];
            }
            currMax += 1;
            maxi = max(maxi, currMax);
        }
        return maxi;
    }
};