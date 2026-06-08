class MyStack {
public:
 queue<int>q;
        queue<int>q1;
    MyStack() {
       
    }
    
    void push(int x) {
        if(q.empty()){
            q.push(x);
            while(!q1.empty()){
                q.push(q1.front());
                q1.pop();
            }
        }
        else{
             q1.push(x);
            while(!q.empty()){
                q1.push(q.front());
                q.pop();
            }
        }
    }
    
    int pop() {
        if(!q.empty()){
            int val=q.front();
            q.pop();
            return val;
        }        
        else{
            int val=q1.front();
            q1.pop();
            return val;
        }
    }
    
    int top() {
        if(!q.empty()){
            int val=q.front();

            return val;
        }        
        else{
            int val=q1.front();
            return val;
        }
    }
    
    bool empty() {
        if(q.empty()&&q1.empty())return true;
        return false;
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