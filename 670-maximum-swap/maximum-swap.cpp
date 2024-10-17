class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        string comp = nums;
        sort(comp.rbegin(), comp.rend());  

        int i = 0;
        while(i < nums.size()){
            if(nums[i] != comp[i]) {
                int index = nums.find_last_of(comp[i]);  
                swap(nums[i], nums[index]);
                break;
            }
            i++;
        }

        return stoi(nums);
    }
};
