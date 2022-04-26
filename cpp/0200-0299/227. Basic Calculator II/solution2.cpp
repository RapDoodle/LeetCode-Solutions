class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char op = '+';
        int num = 0, n = s.length();
        
        // Because '*' and '/' have higher precedence
        // than '+' and '-', first calculate the values
        // for multiplication and division. The stack
        // should only contain numbers to be sumed up.
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                // String to integer
                num = (s[i]-'0') + num*10;
            }
            if ((!isdigit(s[i]) && s[i] != ' ') 
                || i == n - 1) {
                // When it is an operator (or the end of
                // the string), "commit" the sub-
                // expression to the left.
                switch(op) {
                    case '+':
                        stk.push(num);
                        break;
                    case '-':
                        // a + (-b)
                        stk.push(-num);
                        break;
                    case '*':
                        stk.top() *= num;
                        break;
                    case '/':
                        stk.top() /= num;
                        break;
                }
                
                // Change the operator and reset num
                op = s[i];
                num = 0;
            }
        }
        
        // Sum up all the elements in the stack, equivalent
        // to perform the '+' and '-' operations.
        int sum = 0; 
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        
        return sum;
    }
};