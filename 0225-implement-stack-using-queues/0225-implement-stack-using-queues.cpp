class MyStack {
public:
    queue<int> q; // A queue to store elements

    MyStack() {
        // Constructor: Initializing the stack (queue).
    }
    
    void push(int x) {
        q.push(x); // Add element 'x' to the queue.
    }
    
    int pop() {
        if(q.empty()){
            return -1; // If the stack (queue) is empty, return -1 indicating failure.
        }
        for(int i = 0 ; i < q.size()-1 ; i++){
            int a = q.front(); // Store the front element in a variable 'a'.
            q.pop(); // Remove the front element from the queue.
            q.push(a); // Push the front element to the back of the queue (rotate elements).
        }
        int front = q.front(); // The last element in the queue is now at the front.
        q.pop(); // Remove the front element, effectively popping it from the stack.
        return front; // Return the popped element.
    }
    
    int top() {
        if(q.empty()){
            return -1; // If the stack (queue) is empty, return -1 indicating failure.
        }
        for(int i = 0 ; i < q.size()-1 ; i++){
            int a = q.front(); // Store the front element in a variable 'a'.
            q.pop(); // Remove the front element from the queue.
            q.push(a); // Push the front element to the back of the queue (rotate elements).
        }
        int topi = q.front(); // The last element in the queue is now at the front.
        q.pop(); // Remove the front element, but keep it to push back later (to maintain the stack order).
        q.push(topi); // Push the front element to the back of the queue (restore original order).
        return topi; // Return the top element without popping it.
    }
    
    bool empty() {
        return q.empty(); // Check if the stack (queue) is empty.
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