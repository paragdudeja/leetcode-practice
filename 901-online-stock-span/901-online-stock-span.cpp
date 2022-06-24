class StockSpanner {
private:
    stack<pair<int, int>> st;
    int days;
public:
    StockSpanner() {
        days = 0;
    }
    
    int next(int price) {
        days++;
        while(!st.empty() && st.top().first <= price)
            st.pop();
        int span = st.empty() ? days : days - st.top().second;
        st.push({price, days});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */