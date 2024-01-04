class Solution {
public:
    void mergeInPlace(vector<int>& arr, int start, int mid, int end){
       int total_len = end-start+1;
       int gap = (total_len/2) + (total_len%2);
       while(gap>0){
           int i = start, j= start+gap;
           while(j<=end){
               if(arr[i]>arr[j]){
                   swap(arr[i],arr[j]);
               }
               i++,j++;
           }
           if(gap>1){
           gap= (gap/2)+(gap%2);
           }
           else{
               gap=0; //because after gap becomes 1 , if we apply formula for updation of gap, we will get 1 again. Therefore we will update gap as 0 once gap=1 is used.
           }
       }
    }

    void mergeSort(vector<int>& arr, int start, int end){
        if(start>=end){
            return;
        }
        // int mid = start + (end-start)/2;
        int mid = (start+end)>>1;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1, end);
        mergeInPlace(arr,start,mid,end);
    }
    
    vector<int> sortArray(vector<int>& arr) {
        mergeSort(arr,0,arr.size()-1);
        return arr;
    }
};