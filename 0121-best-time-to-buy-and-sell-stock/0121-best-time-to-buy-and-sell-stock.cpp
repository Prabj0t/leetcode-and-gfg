class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX;
        int profit = 0;
        int ans = 0;
        for(int i = 0 ; i < prices.size() ; i++){
            if(prices[i] < lsf){
                lsf = prices[i];
            }
            
            
            profit = prices[i] - lsf;
            if( profit > ans){
                ans = profit;
            }
        }
        return ans;
    }
};