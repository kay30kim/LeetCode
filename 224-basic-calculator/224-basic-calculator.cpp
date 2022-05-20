class Solution {
public:
    int calculate(string s) {
        stack<StackFrame> stk;
        int res = 0;
        int sign = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if (isdigit(s[i])) {
                int start = i;
                while (i + 1 < s.length() && isdigit(s[i + 1])) { i++; }
                res += sign * stoi(s.substr(start, i + 1 - start));
            }
            else if (s[i] == '(') {
                stk.push(StackFrame(res, sign));
                res = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                res = stk.top().base + stk.top().sign * res;
                stk.pop();
            }
        }

        return res;
    }

private:
    struct StackFrame {
        int base;
        int sign;
        StackFrame(int base, int sign) : base(base), sign(sign) {};
    };
};