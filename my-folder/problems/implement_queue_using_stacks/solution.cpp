class MyQueue {
public:

    stack<int> inorder;

    MyQueue() {
    }

    void inorder_push(stack<int> &st,int n)
    {
        if(st.empty()){
            st.push(n);
            return;
        }
        int t=st.top();
        st.pop();
        inorder_push(st,n);
        st.push(t);
    }

    void push(int x) {
        inorder_push(inorder,x);
    }
    
    int pop() {
        int t=inorder.top();
        inorder.pop();
        return t;
    }
    
    int peek() {
        return inorder.top();
    }
    
    bool empty() {
        return inorder.empty();
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