class Solution {
public:

    void printstack(stack<int> st){
        while(!st.empty())
        {
            cout<<st.top()<<endl;
            st.pop();
        }
    }

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int k=0;
        for(int i=0;i<pushed.size();i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && popped[k]==st.top()){
                k++;
                st.pop();
            }
        }
        // printstack(st);
        for(;k<popped.size();k++)
        {
            if(popped[k]==st.top())
            st.pop();
        }
        return st.empty();
    }
};