class MinStack {
public:
    stack<int>st;
    stack<int>temp;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(temp.empty() || temp.top() > val) temp.push(val);
        else temp.push(temp.top());
    }
    
    void pop() {
        st.pop();
        temp.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return temp.top();
    }
};

