class Solution {
public:
    // PIVOT FINDING
int findPivot(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
        {
            return mid - 1;
        }
        if (arr[start] >= arr[mid])
        {
            // left search
            end = mid - 1;
        }
        else
        {
            // right search
            start = mid ;
        }
        mid = start + (end - start) / 2;
    }
    return start; //for single element in array
}

//BINARY SEARCH
int binarySearch(vector<int> arr, int target, int start, int end)
{
    int mid = start + (end - start) / 2;
    
    while (start <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            // search on left
            end = mid - 1;
        }
        else
        {
            // search  on right
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    // if not found
    return -1;
}

     
    int search(vector<int>& nums, int target) {
         int pivot = findPivot(nums);
    if (target >= nums[0] && target <= nums[pivot])
    {
        // search in array A

        int search = binarySearch(nums, target, 0, pivot);
        return search;
    }
    if (pivot+1 < nums.size() && target >= nums[pivot + 1] && target <= nums[nums.size() - 1])
    {
        // search in array B

        int search = binarySearch(nums, target, pivot+1, nums.size()-1);
        return search;
    }
    //if not found
    return -1;
    }
};