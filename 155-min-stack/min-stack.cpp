class MinStack {
public:
    /** initialize your data structure here. */
   stack<long> st;
long min;
/** initialize your data structure here. */
MinStack() {
    
}

void push(int val) 
{
    if(st.empty())
    {
        st.push(val);
        min=val;
    }
    else if(val<=min)
    {
        st.push(2ll*val-min);
        min=val;
    }
    else
    {
        st.push(val);
    }
}

void pop() 
{
     if(st.empty()) 
         return;
    long t=st.top();
    if(t<min)
    {
        min=2ll*min-t;
    }
    st.pop();
}

int top() 
{
    
    if(st.empty())
        return -1;
    long t=st.top();
    if(t<min)
    {
        return min;
    }
    else 
        return t;
}

int getMin() 
{
    if(st.empty())
        return -1;
    else
    return min;
}};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */