class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //two pointer approach
        int l=0; 
        int h=arr.size()-1;
        vector<int> ans;
        while(h-l >= k){
            if(x-arr[l] > arr[h]-x){
                l++;
            }
            else{
                h--;
            }
        }
        for(int i=l; i<=h; i++ ){
           ans.push_back(arr[i]);
        }
         return ans;
    }
};