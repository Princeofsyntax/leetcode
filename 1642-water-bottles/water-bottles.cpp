class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
         int totalDrank = numBottles; // start by drinking all the full bottles you have
        
        while (numBottles >= numExchange) {
            int newBottles = numBottles / numExchange; // number of new full bottles obtained by exchange
            int leftOver = numBottles % numExchange;  // leftover empty bottles after exchange
            
            totalDrank += newBottles; // add the new full bottles to the total count
            numBottles = newBottles + leftOver; // update the number of full bottles we have
        }
        
        return totalDrank;
    }
};