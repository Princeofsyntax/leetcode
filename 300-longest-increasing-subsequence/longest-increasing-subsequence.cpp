class Solution {
public:
        int solveUsingOptimization(vector<int> &arr, int curr, int prev)
        {
            int n = arr.size();
            vector<int> currRow(n + 1, 0);
            vector<int> nextRow(n + 1, 0);

            // move opposite to the top down approach
            for (int curr = n - 1; curr >= 0; curr--)
            {
                for (int prev = curr - 1; prev >= -1; prev--)
                {
                    // include
                    int include = 0;
                    if (prev == -1 || arr[curr] > arr[prev])
                    {
                        include = 1 + nextRow[curr + 1]; // prev+1 is used to manage when prev becomes -1
                    }
                    // exclude
                    int exclude = 0 + nextRow[prev + 1]; // prev+1 is used to manage when prev becomes -1

                    currRow[prev + 1] = max(include, exclude);
                }
                // shifting
                nextRow = currRow; // as movement is opposite
            }
            return nextRow[0];
        }

    int lengthOfLIS(vector<int> &nums)
        {
            int curr = 0;  // index of current element
            int prev = -1; // index of last element included in subsequence
            int n = nums.size();
            int ans = solveUsingOptimization(nums, curr, prev);
            return ans;
        }

};