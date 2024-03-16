class Solution {
public:
    int numSquaresHelper(int n, vector<int> &dp)
        {
            dp[0] = 1;

            for (int i = 1; i <= n; i++)
            {
                int ans = INT_MAX;
                int start = 1;
                int end = sqrt(i); // as above this the resultant number square will exceed the value n

                while (start <= end)
                {
                    int perfectSquare = start * start;
                    int numberOfPerfectSquares = 1 + dp[i - perfectSquare];
                    if (numberOfPerfectSquares < ans)
                    {
                        ans = numberOfPerfectSquares;
                    }
                    ++start;
                }
                // store answer
                dp[i] = ans;
            }
            return dp[n];
        }

    int numSquares(int n)
        {
            // create dp
            vector<int> dp(n + 1, -1);
            return numSquaresHelper(n, dp) - 1; // as 1 extra will come here
        }
};