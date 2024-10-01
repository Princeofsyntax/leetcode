class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderFreq;
    
        for (int num : arr) {
            int rem = ((num % k) + k) % k;  // Handle negative numbers 
            remainderFreq[rem]++;
        }
        
        for (int num : arr) {
            int rem = ((num % k) + k) % k;
            
           if (rem == 0) {
                if (remainderFreq[rem] % 2 != 0) {
                    return false; 
                }
                remainderFreq[rem] -= 2;
            }
            else {
                int complement = k - rem;
                
                if (remainderFreq[rem] > remainderFreq[complement]) {
                    return false;
                }
                
                remainderFreq[rem]--;
                remainderFreq[complement]--;
            }
        }
        
        return true;
        }
};