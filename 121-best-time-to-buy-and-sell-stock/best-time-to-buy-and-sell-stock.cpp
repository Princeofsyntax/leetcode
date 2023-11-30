class Solution {
public:

    void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit){
     //base case
      if( i == prices.size()){ return;}

     //1 case solution
     if(minPrice > prices[i]){ minPrice = prices[i];};
     int todaysProfit = prices[i]-minPrice;
     if(todaysProfit > maxProfit){ maxProfit = todaysProfit;}

     //recursion
     maxProfitFinder(prices,i+1,minPrice,maxProfit);

}

    int maxProfit(vector<int>& prices) {
         int minPrice = INT_MAX;
         int maxProfit = INT_MIN;
         maxProfitFinder(prices,0,minPrice,maxProfit);
        return maxProfit;
    }
};