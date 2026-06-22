class MinStack {
public:
  stack<long long>st;

  long long mini=1e9;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini=value;
        }
        else if(mini<value)st.push(value);
        else if(mini>=value){
            st.push(2LL*value-mini);
            mini=value;
        }
    }
    
    void pop() {
        if(st.top()<=mini){
            mini=2*mini-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<=mini)return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */