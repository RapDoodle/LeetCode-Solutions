class MyQueue {
private:
    stack<int> in, out;
    
    void in2out() {
        // The stack `out` contains the order of the `in` stack  
        // in reverse.
        // When the `out` stack is not empty, wait until the `out`
        // is empty before reversing the elements in `in` to ensure
        // the order is correct.
        if (!out.empty())
            return;
        
        // Pop every element in the `in` stack and push it to
        // the `out` stack. [1,2,3]<-top becomes [3,2,1]<-top.
        // `out` must be empty before popping elements from `in`.
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
public:
    MyQueue() {}
    
    void push(int x) {
        // Note: Elements are not transferred to `out` until
        // either pop or peek in invoked, and `out` is empty.
        in.push(x);
    }
    
    int pop() {
        in2out();
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        in2out();
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */