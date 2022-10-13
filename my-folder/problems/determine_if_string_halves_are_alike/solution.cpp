class Solution {
public:
    bool halvesAreAlike(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                s[i]=s[i]+32;
        }
        string s1,s2;
        int l=s.size();
        for(int i=0;i<l/2;i++)
            s1.push_back(s[i]);
        for(int i=l/2;i<l;i++)
            s2.push_back(s[i]);
        int c1=0,c2=0;
        for(int i=0;i<l/2;i++)
        {
            if(s1[i]=='a' || s1[i]=='e' || s1[i]=='i'|| s1[i]=='o'|| s1[i]=='u')
                c1++;
            if(s2[i]=='a' || s2[i]=='e' || s2[i]=='i'|| s2[i]=='o'|| s2[i]=='u')
                c2++;
        }
        return c1==c2;
    }
};