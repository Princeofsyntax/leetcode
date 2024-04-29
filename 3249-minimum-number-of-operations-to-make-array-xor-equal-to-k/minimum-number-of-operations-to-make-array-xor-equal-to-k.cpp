class Solution {
 public:
  int countNumberOfSetBits(int n){
    int count = 0;
    while(n != 0){
        int lastBit = n & 1;
        if(lastBit) count++;
        //right shift
        n = n>>1;
    }
    return count;
  }

   int minOperations(vector<int>& nums, int k) {
        if (nums.size() < 1) // Handle the case where nums is empty
            return -1; // Or whatever value you want to return for this case

        //Firstly we will take xor of all the numbers in given vector and store in variable xor_calc
        //Then we will do xor of xor_calc with given k and store result in k_calc
        // now we will count number of set bits in k_calc to get answer
        int xor_calc = 0; // Initialize with 0

        for (int i = 0; i < nums.size(); i++) {
            xor_calc = xor_calc ^ nums[i];
        }

        int k_calc = k ^ xor_calc;

        int ans = countNumberOfSetBits(k_calc);

        return ans;
    }
};