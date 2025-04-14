class StockPrice {
public:
    StockPrice(): price_count(), stocks() {
        
    }
    
    void update(int timestamp, int price) {
        // if there is an existing record, delete it
        if(stocks.find(timestamp) != stocks.end()) {
            int curr_price = stocks[timestamp];
            if(price_count[curr_price] > 0) {
                --price_count[stocks[timestamp]];
            }
            if(price_count[curr_price] == 0) {
                price_count.erase(curr_price);
            }
        }

        // add new record
        stocks[timestamp] = price;
        if(price_count.find(price) != price_count.end()){
            ++price_count[price];
        }else{
            price_count[price] = 1;
        }

    }
    
    int current() {
        return prev(stocks.end())->second;
    }
    
    int maximum() {
        return prev(price_count.end())->first;
    }
    
    int minimum() {
        return price_count.begin()->first;
    }

private:
    map<int, int> price_count; // price, number of occurrence
    map<int, int> stocks; // timestamp, price
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */