class Solution {
public:
    int maxSumArrayHelper(vector<int>&arr,int start,int end){
        //base case
        if(start == end){
            return arr[start];  //last level of DnC
        }
        //when recursive tree is formed then when we take left branch sum then it is leftBorderSum and when we take right
        //it is called rightBorderSum, we also take middle sum by considering the root element as well-->maxCrossBorderSum
        int maxLeftBorderSum=INT_MIN, maxRightBorderSum=INT_MIN;
        int mid = start + ((end-start)>>1);
        
        //dividing
        int maxLeftSum=maxSumArrayHelper(arr,start,mid);
        int maxRightSum=maxSumArrayHelper(arr,mid+1,end);

        //maxCrossBorderSum
        //LeftSum
         int leftBorderSum=0, rightBorderSum=0;
         for(int i = mid; i>=start; i--){
             leftBorderSum += arr[i];
             if(leftBorderSum > maxLeftBorderSum){
                 maxLeftBorderSum = leftBorderSum;
             }
         }
         //RightSum
         for(int i = mid+1; i<=end; i++){
             rightBorderSum += arr[i];
             if(rightBorderSum > maxRightBorderSum){
                 maxRightBorderSum = rightBorderSum;
             }
         }
         int crossBorderSum =  maxRightBorderSum +  maxLeftBorderSum ;
         return max(maxLeftSum, max(maxRightSum, crossBorderSum));

    }
    
    int maxSubArray(vector<int>& arr) {
        return maxSumArrayHelper(arr,0,arr.size()-1);
    }
};