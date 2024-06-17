class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned left = 0;
        unsigned right = abs(sqrt(c));

        while(left <= right){
            const unsigned sum = left*left + right*right;

            if(sum == c){
                return true;
            }
            else if(sum < c){
                left++;
            }
            else{
                right--;
            }
        }
       return false;
    }
};