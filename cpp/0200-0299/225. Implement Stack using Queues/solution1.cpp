class MyStack {
private:
    //  The queue contains the elements in the stack order
    //  (the front of the queue is the top of the stack)
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        // Push the new value to the end of the queue
        q.push(x);
        
        // Pop every value in front of the new value,
        // and add it to the end of the queue. After the
        // loop, the newly added value will be at the front 
        // of the queue (equivalent to the top of the stack).
        int n = q.size() - 1;
        for (int i = 0; i < n; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */