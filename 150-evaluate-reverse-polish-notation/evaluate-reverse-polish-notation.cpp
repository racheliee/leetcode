
class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;

        for (auto t: tokens) {
            if (is_operator(t)) {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();

                if (t == "+")
                    s.push(val1+val2);
                else if(t == "-")
                    s.push(val2-val1);
                else if(t == "*")
                    s.push(val1*val2);
                else    
                    s.push(val2/val1);
            } else {
                s.push(stoi(t));
            }
        }

        return s.top();
    }

  private:
    bool is_operator(string str) {
        if (str == "+" || str == "-" || str == "*" || str == "/") {
            return true;
        }
        return false;
    }
};