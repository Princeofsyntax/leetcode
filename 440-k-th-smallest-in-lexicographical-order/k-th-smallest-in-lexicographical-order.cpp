class Solution {
public:
    long long count(long long curr, int n){
        long long steps = 0;
        long long first = curr, last = curr;
        while(first <= n){
            steps += min((long long)(n + 1), last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;

        while(k > 0){
          long long steps = count(curr,n);
          if(steps <= k){
            k -= steps;
            curr++;
          }
          else{
            curr *= 10;
            k--;
          }
        }
        return curr;
    }
};