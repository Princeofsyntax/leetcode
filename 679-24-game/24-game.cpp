class Solution {
public:
    bool helper(vector<double>& nums){
        const double EPSILON = 1e-6;
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24.0) < EPSILON;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)continue;
                vector<double>next;
                for(int k = 0; k < n; k++){
                    if(k != i && k!= j) next.push_back(nums[k]);
                }
                for (int op = 0; op < 4; ++op) {
                    // Optimization: '*' and '+' are commutative, consider only i < j
                    if (op < 2 && i > j) continue;
                    double a = nums[i], b = nums[j];
                    if (op == 0) next.push_back(a + b);
                    if (op == 1) next.push_back(a * b);
                    if (op == 2) next.push_back(a - b);
                    if (op == 3) {
                        if (fabs(b) < EPSILON) continue;
                        next.push_back(a / b);
                    }
                    if (helper(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double>nums(cards.begin(), cards.end());
        return helper(nums);
    }
};