class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int t, v;
        while(q1.size() > 1){
            t = q1.front();
            q2.push(t);
            q1.pop();
        }
        v = q1.front();
        q1.pop();
        while(q2.size() > 0){
            t = q2.front();
            q1.push(t);
            q2.pop();
        }
        return v;
    }
    
    int top() {
        int t, v;
        while(q1.size() > 0){
            t = q1.front();
            q2.push(t);
            q1.pop();
        }
        v = t;
        while(q2.size() > 0){
            t = q2.front();
            q1.push(t);
            q2.pop();
        }
        return v;
    }
    
    bool empty() {
        if(q1.size() > 0){
            return false;
        }
        return true;
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