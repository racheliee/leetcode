
class MinStack {
public:
    MinStack() {
        // none
    }
    
    void push(int val) {
        if(s.empty())
            s.push({val, val});
        else
            s.push({val, min(s.top().second, val)});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }

private:
    stack<pair<int, int>> s;
};