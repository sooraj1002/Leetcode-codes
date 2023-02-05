class Solution {
public:
    bool check(char c)
    {
        if((c>='a'&& c<='z')||(c>='A'&& c<='Z')||(c>='0' && c<='9'))
        return true;
        else
        return false;
    }
    string reverseWords(string s) {
        string temp="";
        stack<string> st;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(check(c))
            {
                temp.push_back(c);
            }
            if(c==' '&& !temp.empty())
            {
                st.push(temp);
                temp="";
            }
        }
        if(!temp.empty())
        st.push(temp);
        string ans;
        while(!st.empty())
        {
            // char c=" ";
            ans +=st.top();
            st.pop();
            if(!st.empty())
            ans.push_back(' ');
        }
        return ans;
    }
};