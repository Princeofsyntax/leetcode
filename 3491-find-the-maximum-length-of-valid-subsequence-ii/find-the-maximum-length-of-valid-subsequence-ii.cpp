class Solution {
public:
    vector<int>*p_nums; //a pointer to current array
    vector<vector<int>>memo;
    vector<vector<int>>next_index; //to tell at which next index we can have same remainder
    int n;
    int k_val;

    int solve(int prev, int target){
        if(prev > n-1) return 0;
        if(memo[prev][target] != -1) return memo[prev][target];

        int prev_rem = (*p_nums)[prev] % k_val; //num[prev_idx] % k
        int expected_rem = (target - prev_rem + k_val) % k_val; //(target-prev_rem)%k
        
        //**The Speed Trick**: Instead of searching, we just look up the next number's index.
        //check where after the current index we will get the expected remainder (in terms of remainder or modulo)
        int next_idx = next_index[prev+ 1][expected_rem]; 

        if (next_idx < n) {
            return memo[prev][target] = 1 + solve(next_idx, target);
        }
        
        return memo[prev][target] = 0;
    }

    int maximumLength(vector<int>& nums, int k) {
        n = nums.size();
        p_nums = &nums;
        k_val = k;
        memo.assign(n, vector<int>(k, -1)); //k remainders are possible

        //Now we will fill nextIndex table which will show at which index you will get that number which will complete your journey to get same modulo
        next_index.assign(n+1, vector<int>(k,n+1));
        for(int i = n-1; i >= 0; i--){
            next_index[i] = next_index[i+1];
            next_index[i][nums[i]%k] = i;  
        }
        int maxi = 1;
        //we will work on remainder now
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int target = (nums[i]%k + nums[j]%k)%k; //just like (nums[i]+nums[j])%k
                //2 numbers are found , now search forward
                int currLength = 2 + solve(j, target);
                maxi = max(currLength, maxi);
            }
        }

        //STEP 2: Handle the Simple Case (All Same Remainders)
        //the longest sequence might just be all the numbers that have the same remainder.
        int max_freq = 0;
        map<int, int> counts;
        for(int num : nums) {
            counts[num % k]++;
        }
        for(auto const& [rem, count] : counts) {
            max_freq = max(max_freq, count);
        }

        return max(maxi, max_freq);

    }
};