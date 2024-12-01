class Solution {
public:
    bool checkIfExist(vector<int>& arr){
        sort(arr.begin(), arr.end());
        int n = arr.size();
        bool check = false;
        for(int i = 0; i < n-1; i++){
           int left = i;
           int right = n-1;
           while(left < right){
                if(arr[left] == 2*arr[right] || 2*arr[left] == arr[right]){
                    return true;
                    break;
                }
                right--;
           }
           if(check)break;
        }
        return false;
    }
};