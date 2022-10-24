class Solution {
public:
    void rem(string& s,int i)
    {
        for(;i<s.size()-2;i++)
            s[i]=s[i+2];
        s.pop_back();
        s.pop_back();
    }
    void backspace(string& s){
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#' && i>0)
            {
                if(s[i-1]>='a'&&s[i-1]<='z')
                {
                    rem(s,i-1);
                    i=0;
                }
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        backspace(s);
        backspace(t);
        for(int i=0;i<s.size();i++)
        {
            if(s[0]=='#')
            {
                for(int j=0;j<s.size()-1;j++)
                    s[j]=s[j+1];
                s.pop_back();
                i=0;
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[0]=='#')
            {
                for(int j=0;j<t.size()-1;j++)
                    t[j]=t[j+1];
                t.pop_back();
                i=0;
            }
        }
        return (s==t);
    }
};