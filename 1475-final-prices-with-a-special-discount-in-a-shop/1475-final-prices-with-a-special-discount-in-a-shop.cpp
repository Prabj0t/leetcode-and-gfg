class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        vector<int> ans;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            if( i == n-1 ){
                ans.push_back(prices[i]);
                
            }
            if( s.empty() ){
                s.push(prices[i]);
            }
            else{
                while (!s.empty() && s.top() > prices[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push(prices[i]);
                    ans.push_back(prices[i]);
                }
                else if (s.top() <= prices[i]){
                    int discountedPrice = prices[i] - s.top();
                    ans.push_back(discountedPrice);
                    s.push(prices[i]);
                }
            }
            
            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};