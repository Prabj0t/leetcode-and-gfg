class StockSpanner {
private:
    stack<pair<int, int>> stockStack;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        if(stockStack.empty() ){
            stockStack.push({price, span});
        }
        else if(price >= stockStack.top().first){
            while(!stockStack.empty() && price >= stockStack.top().first)
            {
                span += stockStack.top().second;
                stockStack.pop();
            }
            stockStack.push({price, span});
        }
        else{
            stockStack.push({price, span});
        }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */