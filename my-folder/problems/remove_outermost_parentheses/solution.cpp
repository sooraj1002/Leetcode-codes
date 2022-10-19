class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int f1=0,count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' && s[i+1]==')' && f1==0 )
            {
                i++;
                continue;
            }
            if(s[i]=='('&& f1==0)
            {
                f1=1;
                continue;
            }
            if(s[i]=='(')
            {
                count++;
                ans.push_back(s[i]);
            }
            if(s[i]==')' && count>0)
            {
                ans.push_back(s[i]);
                count--;
            }
            if(count==0 && s[i+1]==')')
                f1=0;
        }
        return ans;
    }
};