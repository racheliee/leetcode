
class LRUCache {
private:
    int cap;
    list<int> lru; // stores keys, most recent at front
    unordered_map<int, pair<int, list<int>::iterator>> cache; // key -> {val, lru iterator}

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        // move accessed key to front of LRU list
        lru.erase(cache[key].second);
        lru.push_front(key);
        cache[key].second = lru.begin();

        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // key exists, update value and move to front
            lru.erase(cache[key].second);
        } else if (cache.size() == cap) {
            // cache full, evict least recently used (back)
            int lru_key = lru.back();
            lru.pop_back();
            cache.erase(lru_key);
        }

        // insert new key at front
        lru.push_front(key);
        cache[key] = {value, lru.begin()};
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */