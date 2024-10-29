class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
         s = set<int>();
         for(int i = 1; i <= 1000; ++i)
            s.emplace(i);
    }
    
    int popSmallest() {
        int smallest = *s.begin();
        s.erase(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        s.insert(num);
    }

    private:
        set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */