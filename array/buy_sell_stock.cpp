//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int max = 0;
        int lowest=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i] - lowest > max) max = prices[i] - lowest;
            if(prices[i]<lowest) lowest = prices[i];
        }
        return max;
    }
};