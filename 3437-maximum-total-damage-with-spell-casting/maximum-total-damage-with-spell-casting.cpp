class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        //map automatically stores powers in sorted order.
        map<int, int> counts;
        for (int p : power) {
            counts[p]++;
        }

        //extraxt the unique, sorted spell powers into a vector.
        vector<int> unique_powers;
        for (auto const& [p, count] : counts){
            unique_powers.push_back(p);
        }
        
        int n = unique_powers.size();
        if (n == 0) {
            return 0;
        }
        
        vector<long long> dp(n, 0);
        
        //Base case: for the first unique spell, we must take it.
        dp[0] = (long long)unique_powers[0] * counts[unique_powers[0]];
        
        //'j' is a pointer used to efficiently find the last compatible spell.
        int j = 0;
        for (int i = 1; i < n; i++) {
            long long current_power = unique_powers[i];
            long long current_damage = current_power * counts[current_power];
            
            long long damage_if_skipped = dp[i - 1];
            
            while (j < i && unique_powers[j] < current_power - 2) {
                j++;
            }
            
            long long prev_damage = 0;
            if (j > 0) {
                prev_damage = dp[j - 1];
            }
            
            long long damage_if_taken = current_damage + prev_damage;
            
            dp[i] = max(damage_if_skipped, damage_if_taken);
        }
        
        return dp[n - 1];
    }
};