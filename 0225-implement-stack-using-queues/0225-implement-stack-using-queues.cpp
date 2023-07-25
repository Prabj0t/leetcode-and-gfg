class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty()){
            return -1;
        }
        for(int i = 0 ; i < q.size()-1 ; i++){
            int a = q.front();
            q.pop();
            q.push(a);
        }
        int front = q.front();
        q.pop();
        return front;  
    }
    
    int top() {
         if(q.empty()){
            return -1;
        }
        for(int i = 0 ; i < q.size()-1 ; i++){
            int a = q.front();
            q.pop();
            q.push(a);
        }
        int topi = q.front();
        q.pop();
        q.push(topi);
        return topi; 
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