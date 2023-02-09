class MinStack {
private:
    // Two stacks:
    //  s: The original stack
    //  minS: The stack for the minimum values. Values are 
    //    only pushed to the min stack when a value 
    //    smaller or equal to the current minimum is found.
    stack<int> s, minS;
public:
    MinStack() {}
    
    void push(int val) {
        // Push `val` to `minS` if it is the current minimum
        // or a smaller value is inserted.
        s.push(val);
        if (minS.empty() || minS.top() >= val)
            minS.push(val);
    }
    
    void pop() {
        // If the top of the stack is a minimum number
        // (also the minimum at the momemnt), also pop
        // it from `minS`.
        if (!minS.empty() && minS.top() == s.top())
            minS.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */