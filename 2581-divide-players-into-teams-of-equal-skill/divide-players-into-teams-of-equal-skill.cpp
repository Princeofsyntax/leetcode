class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = accumulate(skill.begin(), skill.end(), 0LL);
        int n = skill.size();
        if ((sum * 2) % n != 0) return -1;
        if(n == 2)return skill[0]*skill[1];
        long long target = (sum*2)/n;

        sort(skill.begin(), skill.end());
        long long chemistrySum = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (skill[left] + skill[right] != target) {
                return -1;
            }
            chemistrySum += (long long)skill[left] * skill[right];
            left++;
            right--;
        }
        
        return chemistrySum;
    }
};