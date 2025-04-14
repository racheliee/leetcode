class Solution {
public:
    bool isValid(string s) {
        stack<char> pars;

        for (auto& c : s) {
            switch (c) {
            case ')':
                if (pars.empty() || pars.top() != '(')
                    return false;
                pars.pop();

                break;
            case '}':
                if (pars.empty() || pars.top() != '{')
                    return false;
                pars.pop();
                break;
            case ']':
                if (pars.empty() || pars.top() != '[')
                    return false;
                pars.pop();
                break;
            default:
                pars.push(c);
            }
        }

        if (pars.empty())
            return true;

        return false;
    }
};