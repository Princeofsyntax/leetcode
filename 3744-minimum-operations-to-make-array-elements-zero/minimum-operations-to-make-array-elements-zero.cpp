class Solution {
private:
    long long countTotalOperationsUpTo(long long N) {
        if (N <= 0) return 0;
        //D is the number of digits of N in base 4.
        long long D = 0;
        long long temp = N;
        while (temp > 0) {
            temp /= 4;
            D++;
        }

        long long total_ops = 0;
        long long power_of_4 = 1;

        //calculate sum of operations for all numbers with digits < D.
        //for each digit count 'k' from 1 to D-1:
        //there are 3 * 4^(k-1) numbers with 'k' digits in base 4.
        for (long long k = 1; k < D; ++k) {
            long long count_k_digit_nums = 3 * power_of_4;
            total_ops += k * count_k_digit_nums;
            power_of_4 *= 4;
        }

        //calculate sum of operations for numbers with D digits, from 4^(D-1) up to N.
        //the first D-digit number is 4^(D-1), which is the current value of power_of_4.
        long long first_D_digit_num = power_of_4;
        long long count_D_digit_nums_in_range = N - first_D_digit_num + 1;
        total_ops += D * count_D_digit_nums_in_range;

        return total_ops;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        long long total_min_ops = 0;
        for (const auto& query : queries) {
            long long l = query[0];
            long long r = query[1];

            //the total number of 'floor(x/4)' transformations needed for numbers from l to r
            // is sum(ops(x) for x in [l, r]).
            //this is calculated using a prefix sum approach: S(r) - S(l-1),
            // where S(N) is the sum of operations for numbers from 1 to N.
            long long total_ops_r = countTotalOperationsUpTo(r);
            long long total_ops_l_minus_1 = countTotalOperationsUpTo(l - 1);
            
            long long totalOpsNeeded = total_ops_r - total_ops_l_minus_1;
            
            //each operation performs two transformations.
            //so, the minimum number of operations is ceil(totalOpsNeeded / 2.0),
            // which is (totalOpsNeeded + 1) / 2 using integer division.
            long long min_ops_for_query = (totalOpsNeeded + 1) / 2;
            
            total_min_ops += min_ops_for_query;
        }
        return total_min_ops;
    }
};