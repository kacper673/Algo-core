class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int max_price = 0;
        
        for(int i = n -1; i >=0; i--){
            if(prices[i] > max_price) max_price = prices[i];
            else{
                if(max_price - prices[i] > max_profit) max_profit = max_price - prices[i];
            }
        }

        return max_profit;
    }
};
