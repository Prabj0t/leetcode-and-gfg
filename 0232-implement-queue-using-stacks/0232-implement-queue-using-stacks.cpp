class MyQueue {
public:
    stack<int> in , out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty()){
            while(!in.empty()){
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
        if(out.empty()){
            return -1;
        }
        int topi = out.top();
        out.pop();
        return topi;
        
    }
    
    int peek() {
        
        if(out.empty()){
            while(!in.empty()){
                int a = in.top();
                in.pop();
                out.push(a);
            }
        }
        if(out.empty()){
            return -1;
        }
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