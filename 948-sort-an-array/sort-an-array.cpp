class Solution {
public:
    void merge(vector<int>& arr,vector<int>&temp , int start, int mid, int end){
        int i = start,  j=mid+1,  k = start;
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=end){
            temp[k++]=arr[j++];
        }

        while(start<=end){
            arr[start] = temp[start];
            ++start;
        }
    }

    void mergeSort(vector<int>& arr,vector<int>&temp , int start, int end){
        if(start>=end){
            return;
        }
        // int mid = start + (end-start)/2;
        int mid = (start+end)>>1;
        mergeSort(arr,temp,start,mid);
        mergeSort(arr,temp,mid+1, end);
        merge(arr,temp,start,mid,end);
    }
    
    vector<int> sortArray(vector<int>& arr) {
        vector<int>temp(arr.size(),0);
        mergeSort(arr,temp,0,arr.size()-1);
        return arr;
    }
};