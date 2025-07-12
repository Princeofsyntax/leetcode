class Solution {
public:

    int mn = INT_MAX;
    int mx = INT_MIN;

    void dfs(vector<int>& arr, int round, int firstPlayer, int secondPlayer) {
        int n = arr.size();
        int size = n / 2;

        //check if first and second player comes against each other in this round or not
        for(int i = 0; i < size; i++) {
            if(arr[i] == firstPlayer && arr[n - i - 1] == secondPlayer) {
                mn = min(mn, round);
                mx = max(mx, round);
                return;
            }
        }

        bool f1 = false, f2 = false;//check if first and second player are present or not
        for(int i = 0; i < n; i++) {
            if(arr[i] == firstPlayer) f1 = true;
            if(arr[i] == secondPlayer) f2 = true;
        }

        if(!f1 || !f2) return; //means first and second player are not found

        vector<int> nextarr(size + (n % 2));
        int combinations = (1 << size); //bit manipulation to get number of combination possible for win and loss
        for(int i = 0; i < combinations; i++) {
            int left = 0, right = nextarr.size() - 1;

            //using bit manipulation to get which player wins in each combination for a particular round and then going for next round with all of those combination
            for (int j = 0; j < size; j++) {
                if((1 << j) & i) {
                    nextarr[left] = arr[j];
                    left++;
                } else {
                    nextarr[right] = arr[n - j - 1];
                    right--;
                }
            }

            if (n % 2) {
                nextarr[left] = arr[n / 2];
            }

            dfs(nextarr, round + 1, firstPlayer, secondPlayer);
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> arr(n);
        for(int i = 1; i <= n; i++) arr[i - 1] = i;
        dfs(arr, 1, firstPlayer, secondPlayer);
        return {mn, mx};
    }    
};