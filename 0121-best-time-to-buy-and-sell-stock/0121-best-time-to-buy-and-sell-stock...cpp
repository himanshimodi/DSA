class Solution {
public:
    void maxProfit_util(vector<int> &prices, int i, int &minPrice, int&maxProfit){

        //base case
        if(i == prices.size()){
            return;
        }

        //ek case solve krdo
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        if(prices[i] - minPrice > maxProfit){
            maxProfit = prices[i] - minPrice;
        }

        //recursion
        maxProfit_util(prices, i+1, minPrice, maxProfit);
    }
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        
        maxProfit_util(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};