class Solution {
public:
    //helper function to calculate combinations of 2: C(n, 2) = n * (n - 1) / 2
    //this gives the number of ways to choose 2 items from 'n' items
    long long combinationsOfTwo(int value) {
        return 1LL * value * (value - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        //if total candies exceed what 3 children can get (3 * limit),
        //it's impossible to distribute without violating the limit
        if (n > 3 * limit) {
            return 0;
        }

        //total ways to distribute 'n' candies among 3 children
        //without any restriction is (n + 2 choose 2)
        long long validWays = combinationsOfTwo(n + 2);

        //subtract cases where at least one child gets more than 'limit' candies
        //for each child, if they get more than 'limit', it violates the condition
        if (n > limit) {
            validWays -= 3 * combinationsOfTwo(n - limit + 1);
        }

        //add back the cases that were subtracted more than once
        //these are cases where two children exceeded the limit
        if (n - 2 >= 2 * limit) {
            validWays += 3 * combinationsOfTwo(n - 2 * limit);
        }
        
        return validWays;
    }
};
