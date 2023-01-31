class Solution
{

public:

    void empty(stack<char> &st,int &b)
    {
        if(st.empty())
        return;

        b=0;
        while(!st.empty())
        {
            // cout<<st.top()<<" ";
            st.pop();
            b++;
        }
        cout<<endl;
    }

    int lengthOfLastWord(string s)
    {
        stack<char> st;
        int b=0;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(c==' ')
            empty(st,b);

            else
            st.push(c);
        }
        empty(st,b);
        return b;
    }
};