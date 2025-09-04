class CustomStack {
public:
    CustomStack(int maxSize) : maxS(maxSize), d() {}

    void push(int x) {
        if (d.size() >= maxS)
            return;
        d.push_back(x);
    }

    int pop() {
        if (d.empty())
            return -1;

        int ret = d.back();
        d.pop_back();
        return ret;
    }

    void increment(int k, int val) {
        int len = d.size();
        for (int i = 0; i < k && i < len; ++i)
            d[i] += val;
    }

private:
    int maxS;
    deque<int> d;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */