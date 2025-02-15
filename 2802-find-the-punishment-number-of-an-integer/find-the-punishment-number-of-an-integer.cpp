class Solution {
public:
     bool backtrack(const string& s, int index, int target, int currentSum) {
        if (index == s.length()) {
            return currentSum == target;
        }
        for (int i = index; i < s.length(); ++i) {
            string substring = s.substr(index, i - index + 1);
            int num = stoi(substring);
            if (backtrack(s, i + 1, target, currentSum + num)) {
                return true;
            }
        }
        return false;
    }

    bool canPartition(int num, int target) {
        string s = to_string(num);
        return backtrack(s, 0, target, 0);
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            if (canPartition(square, i)) {
                sum += square;
            }
        }
        return sum;
    }
};