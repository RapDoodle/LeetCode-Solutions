class Solution {
public:
    int calculate(string s) {
        // If you find this solution difficult to
        // understand, consider starting from
        // solution2.cpp
        int sum = 0;
        char op = '+';
        int num = 0, prevNum = 0, n = s.length();
        
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
                // 
                // In "3+4+5*6", when we reach the second 
                // '+', we are sure that the prevNum 3  
                // can be committed to the sum as it is 
                // guaranteed to be a part of summation.
                // 
                // In "3+4*5+6", when we reach the '*' 
                // operator, prevNum becomes 4*5. The new
                // prevNum will eventually be a part of 
                // summation (3+20+6).
                switch(op) {
                    case '+':
                        sum += prevNum;
                        prevNum = num;
                        break;
                    case '-':
                        sum += prevNum;
                        prevNum = -num;
                        break;
                    case '*':
                        prevNum = prevNum * num;
                        break;
                    case '/':
                        prevNum = prevNum / num;
                        break;
                }
                op = s[i];
                num = 0;
            }
        }
        
        // The summation for the last number
        sum += prevNum;
        return sum;
    }
};