class Solution {
public:
    int minOperations(string s) {
        int count=0;
        string s1,s2;
        for(int i=0;i<s.size();i++)
        {
            s1.push_back('0');
            s2.push_back('1');
        }
        for(int i=0;i<s.size()-1;i=i+2)
        {
            if(s1[i]=='0')
                s1[i+1]='1';
            if(s2[i]=='1')   
                s2[i+1]='0';
        }
        int c1=0,c2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=s1[i])
                c1++;
            if(s[i]!=s2[i])
                c2++;
        }
        if(c1<c2)
            return c1;
        return c2;
    }
};