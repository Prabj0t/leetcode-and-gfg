class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        
        for(int i = n - 1 ; i >= 0 ; i--){
            if( i == n-1 ){
                s.push(prices[i]);
            }
            else{
                while (!s.empty() && s.top() > prices[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push(prices[i]);
                }
                else if (s.top() <= prices[i]){
                    int temp = prices[i];
                    prices[i] = prices[i] - s.top();
                    s.push(temp);
                }
            } 
        }
        return prices;
    }
};