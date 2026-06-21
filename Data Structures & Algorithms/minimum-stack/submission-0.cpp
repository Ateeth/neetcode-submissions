class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
            return;
        } 

        if(val < mini){
            st.push(2LL * val - mini);
            mini = val;

            return;
        }
        st.push(val);
    }
    
    void pop() {
        long long x = st.top();
        st.pop();

        if(x > mini) return;

        mini = 2  * mini - x;
    }
    
    int top() {
        if(st.top() >= mini) return st.top();

        return mini;
    }
    
    int getMin() {
        return mini;
    }
};
