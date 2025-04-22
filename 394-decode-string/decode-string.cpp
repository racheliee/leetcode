class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;
        string current = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0'); // handle multi-digit numbers
            } else if (c == '[') {
                counts.push(k);
                result.push(current);
                k = 0;
                current = "";
            } else if (c == ']') {
                string temp = result.top(); result.pop();
                int repeat = counts.top(); counts.pop();
                for (int i = 0; i < repeat; ++i) {
                    temp += current;
                }
                current = temp;
            } else {
                current += c; // regular characters
            }
        }

        return current;
    }
};
