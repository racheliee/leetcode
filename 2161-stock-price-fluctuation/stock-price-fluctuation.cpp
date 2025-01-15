class StockPrice {
public:
    StockPrice() {}

    void update(int timestamp, int price) {
        int curr_price = -1;
        if (stock_map.count(timestamp)) {
            curr_price = stock_map[timestamp];
            prices.erase(prices.find(curr_price));
        }

        prices.insert(price);
        stock_map[timestamp] = price;
    }

    int current() { return prev(stock_map.end())->second; }

    int maximum() { return *prices.rbegin(); }

    int minimum() { return *prices.begin(); }

private:
    map<int, int> stock_map; // timestamp, count
    multiset<int> prices;    // price, count
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */