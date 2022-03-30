class MyStack {
private:
    //  The queue contains the elements in the stack order
    //  (the front of the queue is the top of the stack)
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        // Create a temporary queue. Insert the new value to
        // the front of the queue (top of the stack). Then, 
        // copy the remaining portion of the original queue 
        // (in stack order) to the new queue.
        queue<int> temp;
        temp.push(x);
        while (!q.empty()) {
            temp.push(q.front());
            q.pop();
        }
        q = temp;
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