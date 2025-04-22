class LRUCache {
public:
    LRUCache(int capacity): cache() {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        
        lru.erase(cache[key].second);
        lru.push_front(key);
        cache[key].second = lru.begin();

        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
            lru.erase(cache[key].second);
        else if (cache.size() == cap) {
            cache.erase(lru.back());
            lru.pop_back();
        }

        lru.push_front(key);
        cache[key] = {value, lru.begin()};
    }

private:
    list<int> lru;
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */