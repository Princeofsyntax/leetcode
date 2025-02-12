class Solution {
public:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums){
        unordered_map<int, vector<int>> digitSumMap;
        for (int num : nums) {
            int sum = sumOfDigits(num);
            digitSumMap[sum].push_back(num);
        }
        int maxSum = -1;
        for (auto& [sum, numbers] : digitSumMap) {
            if (numbers.size() >= 2) {
                sort(numbers.rbegin(), numbers.rend());
                int currentSum = numbers[0] + numbers[1];
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }
        return maxSum;
    }
};