class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;  
        vector<int> negative;  
        vector<int> result(nums.size()); 
        
       for (int num : nums) {
            if (num > 0) {
                positive.push_back(num);
            } else {
                negative.push_back(num);
            }
        }

        int posIndex = 0, negIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                result[i] = positive[posIndex++]; 
            } else {
                result[i] = negative[negIndex++]; 
            }
        }

        return result;
        }
};